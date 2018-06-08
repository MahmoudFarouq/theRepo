package com.sorcerer;

public class DataObject {

    private String textData;
    private String sender;
    private long time;

    DataObject(String sender, String textData){
        this.sender = sender;
        this.textData = textData;
        this.time = System.currentTimeMillis();
    }

    private DataObject(String sender, String textData, long date) {
        this.sender = sender;
        this.textData = textData;
        this.time = date;
    }

    @Override
    public String toString() {
        return "DataObject{Sender: "+sender+", Data: "+textData+", Time: "+time+"}";
    }

    public static DataObject toDataObject(String object){
        int senderIndex = object.indexOf(":");
        int commaIndex  = object.indexOf(",");
        String sender   = object.substring(senderIndex+2, commaIndex);
        int dataIndex   = object.indexOf(":", commaIndex);
            commaIndex  = object.indexOf(",", commaIndex+1);
        String data     = object.substring(dataIndex+2, commaIndex);
        int dateIndex   = object.indexOf(":", commaIndex);
            commaIndex  = object.indexOf("}");
        long date       = Long.parseLong(object.substring(dateIndex+2, commaIndex));
        return new DataObject(sender, data, date);
    }
}
