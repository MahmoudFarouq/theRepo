package com.sorcerer;

import org.jetbrains.annotations.Contract;
import processing.core.PApplet;

import java.util.Random;

public class Main extends PApplet {

    private Random random = new Random();

    private final int ALIVE = 1;
    private final int DEAD  = 0;
    private int gWidth;
    private int x;
    private int y;
    private int[][] grid;


    public void settings() {
        size(600, 600);
    }

    public void setup() {
        gWidth  = 20;
        x = width/gWidth;
        y = height/gWidth;
        grid = new int[x][y];

        background(51);
        stroke(255);
        noFill();
        randomGridInit();
    }

    public void draw()
    {
        frameRate(3);

        background(51);

        //drawGrid();
        fillRects();
        updateGrid();
    }

    private void randomGridInit(){

        grid[14][ 6] = 1;
        grid[14][ 7] = 1;
        grid[13][ 8] = 1;
        grid[15][ 8] = 1;
        grid[14][ 9] = 1;
        grid[14][10] = 1;
        grid[14][11] = 1;
        grid[14][12] = 1;
        grid[13][13] = 1;
        grid[15][13] = 1;
        grid[14][14] = 1;
        grid[14][15] = 1;

        /*grid[15][ 5] = 1;
        grid[14][ 5] = 1;
        grid[13][ 5] = 1;
        grid[14][ 6] = 1;
        grid[14][ 7] = 1;
        grid[14][ 8] = 1;
        grid[15][ 9] = 1;
        grid[13][ 9] = 1;
        grid[15][11] = 1;
        grid[13][11] = 1;
        grid[14][12] = 1;
        grid[14][13] = 1;
        grid[14][14] = 1;
        grid[15][15] = 1;
        grid[14][15] = 1;
        grid[13][15] = 1;*/

        /*grid[10][10] = 1;
        grid[11][10] = 1;
        grid[12][10] = 1;
        grid[9 ][11] = 1;
        grid[10][11] = 1;
        grid[11][11] = 1;*/


        /*int n = 20;
        for(int i = 0; i < n; i++){
            try {
                int _x = random.nextInt(x);
                int _y = random.nextInt(y);

                grid[_x-1][_y-1] = 1;
                grid[_x-1][_y+1] = 1;
                grid[_x+1][_y+1] = 1;

            }catch (Exception ignored){}
        }*/
    }

    private void drawGrid() {
        for(int i = 0; i < width; i+=gWidth){
            line(i, 0, i, height);
            line(0, i, width, i);
        }
    }

    private void fillRects(){
        fill(255);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] == ALIVE){
                    rect(i*gWidth, j*gWidth, gWidth, gWidth);
                }
            }
        }
        noFill();
    }

    private void updateGrid() {
        int[][] newGrid = new int[x][y];
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                newGrid[i][j] = getNextState(i, j);
            }
        }
        grid = newGrid;
    }

    @Contract(pure = true)
    private int getNextState(int i, int j) {
        int sum = getSumNeighbors(i, j);
        if(grid[i][j] == ALIVE && sum <  2){
            return DEAD;
        }else if(grid[i][j] == ALIVE && sum <= 3){
            return ALIVE;
        }else if(grid[i][j] == ALIVE && sum >  3){
            return DEAD;
        }else if(grid[i][j] == DEAD  && sum == 3){
            return ALIVE;
        }
        return DEAD;
    }

    @Contract(pure = true)
    private int getSumNeighbors(int x, int y) {
        int sum = 0;
        for(int i = x-1; i < x+2; i++){
            for(int j = y-1; j < y+2; j++){
                try{
                    sum += grid[i][j];
                }catch (Exception ignored){}
            }
        }
        sum -= grid[x][y];
        return sum;
    }

}
