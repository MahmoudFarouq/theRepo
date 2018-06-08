package com.sorcerer;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // write your code here
        Scanner input = new Scanner(System.in);
        my2048 my = new my2048(4);

        System.out.println((int)' ');

        int i = 100;
        while (i-- > 0){
            my.printBoard();
            System.out.print("EnterMove: ");
            char move = input.next().charAt(0);
            switch (move){
                case 'l':
                    my.makeMove(DIRECTION.LEFT);
                    break;
                case 'r':
                    my.makeMove(DIRECTION.RIGHT);
                    break;
                case 'u':
                    my.makeMove(DIRECTION.UP);
                    break;
                case 'd':
                    my.makeMove(DIRECTION.DOWN);
                    break;
            }
        }

    }




}
