// Programmer: Mohit Redhu S12100962
// File: Week5.java
// Date: 7 April 2019
// Purpose: COIT11222 Assignment One Question Five T119
// The GUI Rocky Dry Cleaners Entry System

import javax.swing.JOptionPane;

public class Week5{
    public static void main(String [] args)
    {
        //Declaration of variables and constants
        String customerName;
        int numberOfGarments = 0;
        int totalGarments = 0;
        double finalCharge = 0;
        double totalCharge = 0;
        double average = 0;
        final int N = 9;

        JOptionPane.showMessageDialog(null,"Welcome to the Rocky Dry Cleaners Entry System");   //Welcome Message

        for(int i=1;i<=N;i++)
        {
            customerName = JOptionPane.showInputDialog(null,
                "Please enter the customer name");      //Takes the input of customerName
            
            numberOfGarments = Integer.parseInt(JOptionPane.showInputDialog(null,
                "Enter the number of plain garments for " + customerName));     //Takes the input of numberOfGarments

            //Calculation of finalCharge
            finalCharge = calculateCharge(numberOfGarments);

            //Displaying the receipt
            JOptionPane.showMessageDialog(null,
                String.format(" ---Receipt---\n"
                + "Customer name: %s\n"
                + "Number of garments: %d\n"
                + "Total charge: $%.2f",customerName, numberOfGarments, finalCharge));

            //Increment of totalCost and totalGarments
            totalCharge += finalCharge;
            totalGarments += numberOfGarments;
        }

        average = totalGarments * 1.0/N;        //Calculation Of Average

        JOptionPane.showMessageDialog(null,
                String.format("The average number of garments per customer is %.2f\n"
                + "The total charges collected is $%.2f", average, totalCharge));
    }

    private static double calculateCharge(int garment)      //Method to calculate finalCharge
    {
        double finalCharge = 0;
        final double initialChargePerGarment = 8.50;
        final double chargeForThreeGarments = 20.0;
        final double chargeAfterThreeGarments = 6.50;

        if(garment < 3)
        {
            finalCharge = initialChargePerGarment * garment;
        }
        else if(garment == 3)
        {
            finalCharge = chargeForThreeGarments;
        }
        else if(garment > 3)
        {
            finalCharge = chargeForThreeGarments + (garment - 3)*chargeAfterThreeGarments;
        }

        return finalCharge;
    }
}