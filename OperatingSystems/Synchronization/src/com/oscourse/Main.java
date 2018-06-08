package com.oscourse;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of Tables: ");
        int numOfTables  = 5; //input.nextInt();
        System.out.println("Enter number of Customers: ");
        int numOfCustomers = 8; //input.nextInt();

        try{
            Restaurant restaurant = new Restaurant(numOfTables, numOfCustomers);
            restaurant.open();
        }catch (Exception ex){
            ex.printStackTrace();
        }
    }
}
