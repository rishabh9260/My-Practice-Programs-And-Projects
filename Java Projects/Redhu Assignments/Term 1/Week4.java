// Programmer: Mohit Redhu S12100962
// File: Week4.java
// Date: 2 April 2019
// Purpose: COIT11222 Assignment One Question Four T119
// The non-GUI Rocky Dry Cleaners Entry System

import java.util.Scanner;

public class Week4{
    public static void main(String[] args)
    {
        //Declaration of Scanner Objects
        Scanner inText = new Scanner(System.in);    //To scan customerName
        Scanner inNumber = new Scanner(System.in);  //To scan number of garments

        //Declaration of variables and constants
        String customerName;
        int numberOfGarments = 0;
        int totalGarments = 0;
        double finalCharge = 0;
        double totalCharge = 0;
        double average = 0;
        final int N = 9;
        final double initialChargePerGarment = 8.50;
        final double chargeForThreeGarments = 20.0;
        final double chargeAfterThreeGarments = 6.50;

        System.out.print("\t\tRocky Dry Cleaners Entry System\n\n");

        for(int i=1;i<=N;i++)
        {
            System.out.print("Please enter the customer name " + i + " ==> ");
            customerName = inText.nextLine();   //Takes the input of customerName
            
            System.out.print("Enter the number of plain garments for " + customerName + " ==> ");
            numberOfGarments = inNumber.nextInt();      //Takes the input of numberOfGarments
            
            //Calculation of finalCharge
            if(numberOfGarments < 3)
            {
                finalCharge = initialChargePerGarment * numberOfGarments;
            }
            else if(numberOfGarments == 3)
            {
                finalCharge = chargeForThreeGarments;
            }
            else if(numberOfGarments > 3)
            {
                finalCharge = chargeForThreeGarments + (numberOfGarments - 3)*chargeAfterThreeGarments;
            }
            
            //Displaying the receipt
            System.out.println("\n ---Receipt---");
            System.out.println("Customer name: " + customerName);
            System.out.println("Number of garments: " + numberOfGarments);
            System.out.printf("Total charge: $%.2f\n\n\n", finalCharge);

            //Increment of totalCost and totalGarments
            totalCharge += finalCharge;
            totalGarments += numberOfGarments;
        }

        average = totalGarments * 1.0/N;        //Calculation Of Average

        System.out.printf("The average number of garments per customer is %.2f\n", average);
        System.out.printf("The total charges collected is $%.2f\n", totalCharge);

        inNumber.close();
        inText.close();
    }
}