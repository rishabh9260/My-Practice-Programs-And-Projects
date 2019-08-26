// Programmer: Mohit Redhu S12100962
// File: Week3.java
// Date: 30 March 2019
// Purpose: COIT11222 Assignment One Question Three T119
// Updating the Rocky Dry Cleaners program to display use of decision statements

import java.util.Scanner;

public class Week3{
    public static void main(String[] args)
    {
        //Declaration of Scanner Objects
        Scanner inText = new Scanner(System.in);    //To scan customerName
        Scanner inNumber = new Scanner(System.in);  //To scan number of garments

        //Declaration of variables and constants
        String customerName;
        int numberOfGarments = 0;
        double totalCharge = 0;
        final double initialChargePerGarment = 8.50;
        final double chargeForThreeGarments = 20.0;
        final double chargeAfterThreeGarments = 6.50;

        System.out.print("Please enter the customer name ==> ");
        customerName = inText.nextLine();   //Takes the input of customerName
        
        System.out.print("\nEnter the number of plain garments for " + customerName + " ==> ");
        numberOfGarments = inNumber.nextInt();      //Takes the input of numberOfGarments

        //Calculation of totalCharge
        if(numberOfGarments < 3)
        {
            totalCharge = initialChargePerGarment * numberOfGarments;
        }
        else if(numberOfGarments == 3)
        {
            totalCharge = chargeForThreeGarments;
        }
        else if(numberOfGarments > 3)
        {
            totalCharge = chargeForThreeGarments + (numberOfGarments - 3)*chargeAfterThreeGarments;
        }
        
        //Displaying the receipt
        System.out.println("\n\n ---Receipt---");
        System.out.println("Customer name: " + customerName);
        System.out.println("Number of garments: " + numberOfGarments);
        System.out.printf("Total charge: $%.2f", totalCharge);

        inNumber.close();
        inText.close();
    }
}