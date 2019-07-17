/*
Programmer: Mohit Redhu S12100962
Course: Programming Fundamentals COIT 11222
File: Order.java
Purpose: Assignment Two -- Rocky Dry Cleaners windowed application Order Class
Date: 31 May 2019
*/

public class Order      //Order Class Implementation
{
    private String customerName;        //Declaring customerName to take the name of customer
    private int garment;        //Declaring garment to input the number of garments

    public Order()      //Default constructor to initialize the fields to default values
    {
        customerName = null;
        garment = 0;
    }

    public Order(String Name, int g)    //Parameterized constructor to initialize the fields to the parameter values
    {
        customerName = Name;
        garment = g;
    }

    public String getCustomerName()     //Get method(accessor) for customerName
    {
        return customerName;
    }

    public int getGarment()     //Get method(accessor) for garment
    {
        return garment;
    }

    public void setCustomername(String name)        //Set method(mutator) for customerName
    {
        customerName = name;
    }

    public void setGarments(int gar)        //Set method(mutator) for garment
    {
        garment = gar;
    }
    
    public double calculateCharge()     //Method to calculate the charge for a single order
    {
        if(garment<=2)
            return garment*8.50;
        else if(garment==3)
            return 20;
        else
            return (20 + (garment-3) * 6.50);
    }
}