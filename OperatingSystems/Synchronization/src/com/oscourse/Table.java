package com.oscourse;

public class Table {
    private String name;

    Table(String name){
        this.name = name;
    }

    @Override
    public String toString(){
        return name;
    }

    public synchronized void SitDown(String customerName) throws InterruptedException{
        System.out.println(name + ": " + customerName + " Sit Down");
        wait(Restaurant.random.nextInt(500) + 100);
    }
    public synchronized void OrderFood(String customerName) throws InterruptedException{
        System.out.println(name + ": " + customerName + " Order Food");
        wait(Restaurant.random.nextInt(1000) + 100);
    }
    public synchronized void EatFood(String customerName) throws InterruptedException{
        System.out.println(name + ": " + customerName + " Eat Food");
        wait(Restaurant.random.nextInt(3715) + 100);
    }
    public synchronized void Leaving(String customerName) throws InterruptedException{
        System.out.println(name + ": " + customerName + " Is Leaving");
    }
}
