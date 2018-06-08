package com.sorcerer;

import java.util.LinkedList;

public class DataStore {

    private LinkedList<DataObject> store;

    DataStore(){
        store = new LinkedList<>();
    }

    public void add(String sender, String data){
        store.add(new DataObject(sender, data));
    }

    public void add(DataObject dataObject){
        store.add(dataObject);
    }

    public int getSize(){
        return store.size();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < store.size(); i++) {
            DataObject dataObject = store.get(i);
            sb.append(i).append(") ").append(dataObject.toString()).append("\n");
        }
        return sb.toString();
    }
}
