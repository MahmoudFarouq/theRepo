import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Client{
    private String clientName;
    private Socket socket;
    private BufferedReader input;
    private DataInputStream receiver;
    private DataOutputStream sender;

    Client(Socket socket, String  clientName) throws Exception{
        this.socket = socket;
        this.clientName = clientName;
        input = new BufferedReader(new InputStreamReader(System.in));
        sender = new DataOutputStream(socket.getOutputStream());
        receiver = new DataInputStream(socket.getInputStream());
        start();
    }

    public void start(){
        startReceiving();
        startSending();
    }

    public void startSending(){
        new Thread(this::SendListener).start();
    }

    public void startReceiving(){
        new Thread(this::ReceiveListener).start();
    }

    private void SendListener() {
        try{
            if(socket.isConnected()) {
                System.out.println("Connected to SERVER Successful. Let's start chat OR type EXIT to Disconnect");
                String msgtoServerString;
                while(true){
                    msgtoServerString = input.readLine();
                    sender.writeUTF(clientName + ": " + msgtoServerString);
                    sender.flush();
                    if(msgtoServerString.equals("end"))
                        break;
                }
                socket.close();
            }else {
                System.out.println("socket is not connected");
            }
        } catch(Exception e){e.printStackTrace();}
    }

    private void ReceiveListener(){
        try{
            String msgReceived = "";
            while(!(msgReceived = receiver.readUTF()).equals("end")) {
                System.out.println(msgReceived);
            }
            System.out.println(clientName + " is Disconnect");
            socket.close();
        } catch(Exception e){e.printStackTrace();}
    }
}
