// Programmer: Mohit Redhu S12100962
// File: Week2.java
// Date: 30 March 2019
// Purpose: COIT11222 Assignment One Question Two T119
// Creating a Rocky Dry Cleaners program to show understanding of data types and arithmetic operators

import java.util.Scanner;

public class Week2{
    public static void main(String[] args)
    {
        //Declaration of Scanner Objects
        Scanner inText = new Scanner(System.in);    //To scan customerName
        Scanner inNumber = new Scanner(System.in);  //To scan number of garments

        //Declaration of variables and constants
        String customerName;
        int numberOfGarments = 0;
        double totalCharge = 0;
        final double chargePerGarment = 8.50;

        System.out.print("Please enter the customer name ==> ");
        customerName = inText.nextLine();   //Takes the input of customerName
        
        System.out.print("\nEnter the number of plain garments for " + customerName + " ==> ");
        numberOfGarments = inNumber.nextInt();      //Takes the input of numberOfGarments

        totalCharge = chargePerGarment * numberOfGarments;    //Calculation of totalCharge

        //Displaying the receipt
        System.out.println("\n\n ---Receipt---");
        System.out.println("Customer name: " + customerName);
        System.out.println("Number of garments: " + numberOfGarments);
        System.out.printf("Total charge: $%.2f", totalCharge);
    }
}