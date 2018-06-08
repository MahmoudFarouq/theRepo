import java.net.Socket;

public class User {

    private String name;
    private Socket socket;
    private Client client;
    private MiddleMan middleMan;

    User(String name){
        this.name = name;
    }

    public boolean enterChatRoom(int port){
        try {
            socket = new Socket("localhost", port);
            client = new Client(socket, name);
            return true;
        }catch (Exception ex){
            ex.printStackTrace();
            return false;
        }
    }

    public boolean startChatRoom(int port){
        try {
            middleMan = new MiddleMan(port);
            enterChatRoom(port);
            return true;
        }catch (Exception ex){
            ex.printStackTrace();
            return false;
        }
    }
}
