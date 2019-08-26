/*
Programmer: Mohit Redhu S12100962
Course: Programming Fundamentals COIT 11222
File: RockyDryCleanersGUI.java
Purpose: Assignment Two -- Rocky Dry Cleaners windowed application
Date: 31 May 2019
*/

import java.awt.FlowLayout;
import java.awt.Font;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;

public class RockyDryCleanersGUI extends JFrame implements ActionListener {

	private static final long serialVersionUID = 1L;
	final int MAX_ORDER = 10; // Constant for the maximum number of orders acceptable
	private Order[] orderArray = new Order[MAX_ORDER];		//Declaring array of Order objects with size MAX_ORDER
	private int currentOrder = 0;		//variable to tell the current order number


	private JLabel titleLabel = new JLabel("Rocky Dry Cleaners Management System"); // program title
	private JLabel nameLabel = new JLabel("Customer name: ");// for prompt
	private JTextField nameField = new JTextField(26);      // for name entry

	private JLabel garmentsLabel = new JLabel("Number of plain garments: ");// for prompt
	private JTextField garmentsField = new JTextField(4);      // for number of garments entry

	private JTextArea displayTextArea = new JTextArea("", 16, 56); // declare text area
	private JScrollPane scrollPane; // scroll pane for the text area

	//  declare all of the buttons
	private JButton enterButton = new JButton("Enter"); // buttons
	private JButton displayButton = new JButton("Display All");
	private JButton searchButton = new JButton("Search");
	private JButton exitButton = new JButton("Exit");


	public RockyDryCleanersGUI()
	{ // constructor create the Gui
		this.setLayout(new FlowLayout());			// set JFrame to FlowLayout

		titleLabel.setFont(new Font("Ariel", Font.BOLD, 22));
		add(titleLabel);
		add(nameLabel);
		add(nameField);
		add(garmentsLabel);
		add(garmentsField);

		// set text area to a monospaced font so the columns can be aligned using a format string
		displayTextArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
		displayTextArea.setEditable(false); 			// make text area read only
		scrollPane = new JScrollPane(displayTextArea); 	// add text area to the scroll pane
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER); // just need vertical scrolling

		add(scrollPane);

		add(enterButton);
		add(displayButton);
		add(searchButton);
		add(exitButton);

		enterButton.addActionListener(this);		// add the action listener to the buttons
		displayButton.addActionListener(this);
		searchButton.addActionListener(this);
		exitButton.addActionListener(this);



		// when the user pushes the system close (X top right corner)
		addWindowListener( // override window closing method
			new WindowAdapter()
			{
				public void windowClosing(WindowEvent e)
				{
					exit();				// Attempt to exit application
				}
			}
		);
	}



	public void actionPerformed(ActionEvent e)
	{ // process the clicks on all of the buttons
		String command = e.getActionCommand();

		if (command.compareTo("Enter") == 0)
			enter();
		else if (command.compareTo("Display All") == 0)
			displayAll();
		else if (command.compareTo("Search") == 0)
			search();
		else if (command.compareTo("Exit") == 0)
			exit();
	}


	private void enter()		//Processes and carries out the following tasks after clicking of enter button
	{
		if(currentOrder == MAX_ORDER)		//Checks if maximum number of orders is reached
		{
			errorMessage("Maximum number of Orders reached!");
			return;
		}

		if(nameField.getText().compareTo("") == 0)	//Checks if the customer name field is empty. It is True when blank
		{
			errorMessage("You must enter Customer Name");
			return;
		}

		if(garmentsField.getText().compareTo("") == 0)	//Checks if the garment field is empty. It is True when blank
		{
			errorMessage("You must enter number of Garments");
			return;
		}

		String customerName = nameField.getText();		//Takes input from the customer text field
		int garments = Integer.parseInt(garmentsField.getText());		//Takes input from the garment field and converts it to an int
		orderArray[currentOrder] = new Order(customerName, garments);	//Initializes the instance of the order object by calling the parameterized constructor

		displayHeading();		//Displays the heading

		display(currentOrder);		//Displays the cureent order details
		nameField.setText("");		//Sets the Name field to blank
		garmentsField.setText("");	//Sets the garment field to blank
		nameField.requestFocus();	//Sets focus to the name field again

		currentOrder++;		//Increments the currentOrder
	}


	private void display(int index)		//Displays the details of the current order
	{
		displayTextArea.append(String.format("%-30s%-17s$%-65.2f\n",
			orderArray[index].getCustomerName(),
			orderArray[index].getGarment(),
			orderArray[index].calculateCharge()));
	}

	private void displayHeading()		//Displays the heading
	{
		displayTextArea.setText(String.format("%-30s%-17s%-6s\n", "Customer Name", "Garments", "Charge"));
		appendLine();
	}


	private void appendLine()		//Adds the line after the heading and when displaying all orders
	{
		displayTextArea.append("-------------------------------------------------------\n");
	}

	private void displayAll()		//Method to display all the orders and the average number of garments and total charge
	{
		double sumOfGarment = 0;		//Local variable to store total number of garments of all orders
		double totalCharge = 0;		//Local variable to store the total charges of all orders

		displayHeading();

		for (int i = 0; i < currentOrder; i++)
		{
			display(i);
			sumOfGarment = sumOfGarment + orderArray[i].getGarment();		//calculate total garments
			totalCharge = totalCharge + orderArray[i].calculateCharge();	//calculate total charge
		}

		double avg = sumOfGarment/currentOrder;		//Variable to store the average number of garments per order
		appendLine();
		displayTextArea.append(String.format("Average garments per Order: %5.2f", avg));		//To display the average no. of garments
		displayTextArea.append(String.format("\nTotal Charge: $%5.2f", totalCharge));	//To display the total charge
		nameField.requestFocus();

		if(currentOrder == 0)		//To check if no order is entered
		{
			errorMessage("No Order Entered");
		}
	}


	private void search()		//To search for a name in the orders and display its details if found
	{
		int flag = 0;		//Variable to mark if the search name is found
		int pos = 0;		//Variable to store the position where the name is found

		String name = null;		//Decalring name variable to store the inputted name
		
		name = JOptionPane.showInputDialog( "Input Name for search");	//Take the name for input
		
		if(name.compareTo("") == 0)	//Checks if the input field is empty.It is True when blank
		{
			errorMessage("You must enter Customer Name");
			return;
		}

		for(int i = 0; i<currentOrder; i++)
		{
			if(name.compareToIgnoreCase(orderArray[i].getCustomerName()) == 0)	//Searches for the name in the orderArray by comparing it with input while ignoring case
			{
				flag = 1;		//Marks that the name is found
				pos = i;		//Stores the position where name is found
				break;		//Exits loop
			}
		}
		
		if(flag == 1)		//If the name is found it displays its details
		{
			displayHeading();
			display(pos);
			nameField.requestFocus();
		}
		else		//Else if not found displays the error nessage
		{
			errorMessage(name + " not found");
		}
	}


	private void exit()		//Closes the program while showing the exit message
	{
		JOptionPane.showMessageDialog(null, "Thank You for using The Rocky Dry Cleaners Management System");

		System.exit(0);
	} // exit

	private void errorMessage(String message)		//Method to display error messages with the message received as parameters
	{
		JOptionPane.showMessageDialog(null, message, "Error", JOptionPane.ERROR_MESSAGE);
	}



	// Main method create instance of class
	public static void main(String[] args)
	{
		RockyDryCleanersGUI f = new RockyDryCleanersGUI();			// Create instance of class
		f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);	// allow the code to close the program
		f.setBounds(200, 100, 470, 440);						// Define position and size of app
		f.setTitle("Rocky Dry Cleaners Management System");		// Set the title of the app
		f.setVisible(true);										// Make the application visible
		f.setResizable(false);									// Make the window not resizable
	} // main

}