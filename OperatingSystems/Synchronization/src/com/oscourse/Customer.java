package com.oscourse;

public class Customer extends Thread {
    public Customer(String name){
        super(name);
    }

    @Override
    public void run() {
        try {
            System.out.println(getName() + " has arrived");
            if (!Restaurant.semaphore.tryAcquire()) {
                System.out.println(getName() + " is Waiting");
                Restaurant.semaphore.acquire();
            }
            Table table = Restaurant.acquireTable();

            table.SitDown(getName());
            table.OrderFood(getName());
            table.EatFood(getName());
            table.Leaving(getName());

            Restaurant.releaseTable(table);
            Restaurant.semaphore.release();
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }
}
