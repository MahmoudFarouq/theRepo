package com.sorcerer;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Client{
    private DataStore dataStore;
    private String clientName;
    private Socket socket;
    private DataInputStream receiver;
    private DataOutputStream sender;

    Client(Socket socket, String  clientName) throws Exception{
        this.socket = socket;
        this.clientName = clientName;

        sender    = new DataOutputStream(socket.getOutputStream());
        receiver  = new DataInputStream(socket.getInputStream());
        dataStore = new DataStore();

        Thread sendingThread = new Thread(this::SendListener);
        Thread receivingThread = new Thread(this::ReceiveListener);

        sendingThread.start();
        receivingThread.start();
    }

    private void SendListener() {
        try{
            if(socket.isConnected()) {
                System.out.println("Connected to SERVER Successful. Let's start chat OR type EXIT to Disconnect");
                while(true){
                    String randomData = FakeDataGenerator.generate(20);
                    String dataObject = new DataObject(clientName, randomData).toString();
                    sender.writeUTF(dataObject);
                    sender.flush();
                    Thread.sleep(2000);
                }
            }else {
                System.out.println("socket is not connected");
            }
        } catch(Exception e){e.printStackTrace();}
    }

    private void ReceiveListener(){
        try{
            DataObject dataReceived;
            int i = 0;
            while(true) {
                dataReceived = DataObject.toDataObject(receiver.readUTF());
                dataStore.add(dataReceived);
                if(i++%10==0){
                    printData();
                }
            }
        } catch(Exception e){e.printStackTrace();}
    }

    public void printData(){
        //System.out.println("client: "+clientName+" -> size: " +  dataStore.getSize());
        System.out.println("client: "+clientName+"\n" + dataStore);
    }
}
