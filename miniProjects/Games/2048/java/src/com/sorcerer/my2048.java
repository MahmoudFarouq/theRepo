package com.sorcerer;

import java.util.Random;

enum DIRECTION{LEFT, RIGHT, UP, DOWN}

public class my2048 {
    private int numRows;
    private int[][] board;
    private Random random;
    private int availNumbers[] = {2, 2, 2, 4, 4};
    private char specialEmpty = '_';
    my2048(int num_rows){
        numRows = num_rows;
        board = new int[numRows][numRows];
        random = new Random();
        initializeBoard();
        addNewNum();
    }

    boolean makeMove(DIRECTION direction){
        if(gameOver())
            return false;

        switch (direction){
            case RIGHT:
            case LEFT:
                moveHorizontal(direction);
                break;
            case UP:
            case DOWN:
                moveVertical(direction);
                break;
        }
        addNewNum();
        return true;
    }

    void printBoard(){
        for(int[] row : board){
            for(int cell : row){
                if(cell == specialEmpty)
                    cell = 0;
                System.out.printf("%5d", cell);
            }
            System.out.println();
        }
    }

    private void moveHorizontal(DIRECTION direction){
        int start, end, step;
        if(direction == DIRECTION.RIGHT) {
            start = numRows-1;
            end = -1;
            step = -1;
        }else {
            start = 0;
            end = numRows;
            step = 1;
        }
        for(int i = 0; i < numRows; i++){
            moveRowHorizontal(board[i], start, end, step);
        }
    }

    private void moveVertical(DIRECTION direction){
        int start, end, step;
        if(direction == DIRECTION.DOWN) {
            start = numRows-1;
            end = -1;
            step = -1;
        }else {
            start = 0;
            end = numRows;
            step = 1;
        }

        for(int i = 0; i < numRows; i++){
            int column[] = new int[numRows];
            for (int j = 0; j < numRows; j++){
                column[j] = board[j][i];
            }
            moveRowHorizontal(column, start, end, step);
            for (int j = 0; j < numRows; j++){
                board[j][i] = column[j];
            }
        }
    }

    private void moveRowHorizontal(int[] row, int start, int end, int step){
        int lastStop = start-step;
        for(int i = start; i != end; i+=step){
            for(int k = i-step; k != lastStop; k-=step){
                if(row[k] == specialEmpty && row[i] != specialEmpty){
                    row[k] = row[i];
                    row[i] = specialEmpty;
                    i = k;
                }else if(row[k] == row[i] && row[i] != specialEmpty){
                    row[k] *= 2;
                    row[i] = specialEmpty;
                    i = k;
                }else if(row[k] != row[i] && row[i] != specialEmpty && row[k] != specialEmpty) {
                    lastStop = k;
                    break;
                }
            }
        }
    }

    private void addNewNum(){
        while (true) {
            int x = random.nextInt(4);
            int y = random.nextInt(4);
            if( board[x][y] == specialEmpty){
                board[x][y] = availNumbers[ random.nextInt(4) ];
                return;
            }
        }
    }

    private void initializeBoard(){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numRows; j++){
                board[i][j] = specialEmpty;
            }
        }
    }

    private boolean gameOver(){
        for(int[] row : board){
            for(int cell : row){
                if(cell == specialEmpty){
                    return false;
                }
            }
        }
        return true;
    }

}
    /*
    private void moveRight(int[] row){
        int lastStop = numRows;
        for(int i = numRows-1; i >= 0; i--){
            for(int k = i+1; k != lastStop; k++){
                if(row[k] == ' ' && row[i] != ' '){
                    row[k] = row[i];
                    row[i] = ' ';
                    i = k;
                }else if(row[k] == row[i] && row[i] != ' '){
                    row[k] *= 2;
                    row[i] = ' ';
                    i = k;
                }else if(row[k] != row[i] && row[i] != ' ' && row[k] != ' ') {
                    lastStop = k;
                    break;
                }
            }
        }
    }
     */