package com.sorcerer;
import java.util.Arrays;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {

        Box<Item> box = new Box<>(20);
        box.add(new Item("btngan" , 13));
        box.add(new Item("kosa"   , 8));
        box.add(new Item("felfel" , 5));
        box.add(new Item("btates" , 6));
        box.add(new Item("5yar"   , 13));
        box.add(new Item("tmatem" , 1));
        box.add(new Item("4awerma", 118));
        box.add(new Item("manga"  , 280));

        box.sort();

        for(Item item : box){
            System.out.println(item);
        }
    }
}


class Box<T> implements Iterable<T> {
    private T[] content;
    private int iterator = 0;
    private int size = 0;

    @SuppressWarnings (value="unchecked")
    Box(int n){
        try {
            content = (T[]) new Object[n];
        }catch (ClassCastException EX){
            EX.printStackTrace();
        }
    }

    boolean add(T item){
        if(iterator >= content.length)
            return false;
        content[size++] = item;
        return true;
    }

    void sort(){
        Arrays.sort(content, 0, size);
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            @Override
            public boolean hasNext() {
                return iterator < size;
            }

            @Override
            public T next() {
                return content[iterator++];
            }
        };
    }
}

class Item implements Comparable<Item>{
    private int price;
    private String name;

    Item(String name, int price){
        this.name = name;
        this.price = price;
    }

    @Override
    public int compareTo(Item o) {
        //return this.price - o.price;
        return this.name.compareTo(o.name);
    }

    @Override
    public String toString(){
        return String.format("ItemName: %s, price: %s", name, price);
    }
}

