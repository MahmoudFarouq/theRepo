package com.sorcerer;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

public class MiddleMan {

    private ServerSocket serverSocket;
    private LinkedList<DataInputStream> dins;
    private LinkedList<DataOutputStream> douts;
    private LinkedList<DataObject> dataObjects;


    MiddleMan(int port) throws Exception{
        serverSocket = new ServerSocket(port);
        dins = new LinkedList<>();
        douts = new LinkedList<>();
        dataObjects = new LinkedList<>();
        startServing();
    }

    private void startServing(){
        System.out.println("MiddleMan is Established and waiting for Peers..");
        while (true) {
            try{
                Socket last = serverSocket.accept();
                dins.add(new DataInputStream(last.getInputStream()));
                douts.add(new DataOutputStream(last.getOutputStream()));
                System.out.println( "Connected socket with INetAddress: " + last);

                sendPreviousDataToLastSocket();
                startListeningToLastSocket();

            }catch (Exception ex){
                ex.printStackTrace();
            }
        }
    }

    private void startSendingAnyInputByServerToAllPeers(){
        new Thread(() -> {
            try {
                BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
                String msgout;
                while(true){
                    System.out.println("size= "+douts.size());
                    msgout = input.readLine();
                    for(DataOutputStream dataOutputStream : douts){
                        dataOutputStream.writeUTF(msgout);
                        dataOutputStream.flush();
                    }
                }
            }catch (Exception ex){ex.printStackTrace();}
        }).start();
    }

    private void sendPreviousDataToLastSocket(){
        try{
            DataOutputStream dos = douts.getLast();
            for(DataObject dataObject : dataObjects){
                dos.writeUTF(dataObject.toString());
                dos.flush();
            }
        }catch (Exception ex){ex.printStackTrace();}
    }

    private void startListeningToLastSocket(){
        new Thread(() -> {
            try {
                DataInputStream din = dins.getLast();       //read from client
                String msg;
                int i = 50;
                while(i-- > 0){
                    msg = din.readUTF();
                    dataObjects.add(DataObject.toDataObject(msg));
                    for(DataOutputStream dataOutputStream : douts){
                        dataOutputStream.writeUTF(msg);
                        dataOutputStream.flush();
                    }
                }
            }catch (Exception ex){
                ex.printStackTrace();
            }
        }).start();
    }
}
