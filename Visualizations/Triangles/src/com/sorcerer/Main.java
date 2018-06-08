package com.sorcerer;

import processing.core.PApplet;

public class Main extends PApplet{

    public void settings(){
        size(600, 600);
    }

    public void setup(){

        background(51);
        stroke(255);
        noFill();

        drawTries(300, 50, 50, 550, 550, 550, 0);


        noLoop();

    }


    private void drawTries(int x1, int y1, int x2, int y2, int x3, int y3, int level){
        if(level > 5)
            return;
        //triangle(x1, y1, x2, y2, x3, y3);
        int nx2 = (x1-x2)/2+x2;
        int ny2 = (y2-y1)/2+y1;
        int nx3 = (x3-x1)/2+x1;
        int ny3 = (y3-y1)/2+y1;
        triangle(x1, y3, nx2,ny2,nx3,ny3);
        drawTries(x1, y1, nx2, ny2, nx3, ny3, level+1); // upper
        drawTries(nx2, ny2, x2, y2, x1, y3, level+1); // left
        drawTries(nx3, ny3, x1, y3, x3, y3, level+1); // right
    }

}
