import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

public class MiddleMan {
    private int port = 4444;
    private ServerSocket serverSocket;
    LinkedList<DataInputStream> dins;
    LinkedList<DataOutputStream> douts;

    MiddleMan(int port) throws Exception{
        this.port = port;
        serverSocket = new ServerSocket(this.port);
        dins = new LinkedList<>();
        douts = new LinkedList<>();
        startServing();
    }

    private void startServing(){
        System.out.println("Server is Established and waiting for Peers..");

        //startSendingAnyInputByServerToAllPeers();

        while (true) {
            try{
                Socket last = serverSocket.accept();
                dins.add(new DataInputStream(last.getInputStream()));
                douts.add(new DataOutputStream(last.getOutputStream()));
                System.out.println( "Connected socket with INetAddress: " + last);

                startListeningToThreadWithSocket(last);

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

    private void startListeningToThreadWithSocket(Socket last){
        new Thread(() -> {
            try {
                Socket s = last;
                DataInputStream din = new DataInputStream(s.getInputStream());       //read from client
                String msgin = "";
                while(!msgin.equals("end")){
                    msgin = din.readUTF();
                    System.out.println(msgin);
                    for(DataOutputStream dataOutputStream : douts){
                        dataOutputStream.writeUTF(msgin);
                        dataOutputStream.flush();
                    }
                }
                s.close();
            }catch (Exception ex){ex.printStackTrace();}
        }).start();
    }
}
