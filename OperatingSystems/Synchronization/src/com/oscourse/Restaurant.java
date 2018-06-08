package com.oscourse;

import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;
import java.util.concurrent.Semaphore;

class Restaurant {
    public static Random        random;
    public static Semaphore     semaphore;
    private volatile static Stack<Table> freeTables;
    private ArrayList<Customer> customers;

    public Restaurant(int numOfTables, int numOfCustomers){
        random     = new Random();
        customers  = new ArrayList<>(numOfCustomers);
        freeTables = new Stack<>();
        semaphore  = new Semaphore(numOfTables);
        for (int i = 1; i <= numOfCustomers; i++){
            customers.add( new Customer( "C"+i) );
        }
        for (int i = numOfTables; i > 0; i--){
            freeTables.add( new Table( "Table "+i ) );
        }
    }

    public static synchronized Table acquireTable(){
        return Restaurant.freeTables.pop();
    }

    public static synchronized void releaseTable(Table table){
        freeTables.push(table);
    }

    public void open(){
        for (Customer customer : customers) {
            customer.start();
        }
    }
}
