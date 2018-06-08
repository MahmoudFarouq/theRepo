import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner input = new Scanner(System.in);

        System.out.println("Please Enter your name: ");
        String name = input.nextLine();
        System.out.println("Welcome " + name);

        User user = new User(name);

        System.out.println("1) Start chat room");
        System.out.println("1) Enter chat room");

        int choice = input.nextInt();
        switch (choice){
            case 1:
                user.startChatRoom(4444);
                break;
            case 2:
                user.enterChatRoom(4444);
                break;
            default:
                System.out.println("Wrong input, Fuck off!");
        }
    }
}
