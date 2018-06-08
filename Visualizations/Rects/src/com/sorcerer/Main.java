package com.sorcerer;

import processing.core.PApplet;

public class Main extends PApplet{

    int Y = 100;
    int X = (int)(((Y/2)*cos(radians(30)))/sin(radians(30)));


    int y = Y/2;
    int x = X/3;
    int Z = y;

    private Mo3ian mo3ian1 = new Mo3ian(x,0,0,y, x);
    private Mo3ian mo3ian2 = new Mo3ian(0,-y,0,y, x);

    private float degree = 0;

    public void setup() {
        background(51);
        noFill();
        stroke(255);
        translate(300,300);
        line(-600, 0, 600, 0);
        line(0, -600, 0, 600);


        //noLoop();
    }
    public void settings() {
        size(600,600);
    }

    public void draw()
    {
        background(51);
        translate(300,300);


        for(int i = 0; i < 5; i++)
        {
            pushMatrix();
            translate(-3*Y, (i-2)*Y);
            for(int j = 0; j < 5; j++)
            {
                translate(Y, 0);
                drawFour();
            }
            popMatrix();
        }


        degree += 0.9;
        degree %= 360;

        mo3ian1.updateValues();
        mo3ian2.updateValues();
    }

    private void drawFour() {
        pushMatrix();
        translate(-Z, 0);
        rotate(radians(degree));
        mo3ian1.drawMo3ian();
        mo3ian2.drawMo3ian();
        popMatrix();

        pushMatrix();
        translate(Z, 0);
        rotate(radians(180+degree));
        mo3ian1.drawMo3ian();
        mo3ian2.drawMo3ian();
        popMatrix();

        pushMatrix();
        translate(0, Z);
        rotate(radians(90+degree));
        mo3ian1.drawMo3ian();
        mo3ian2.drawMo3ian();
        popMatrix();

        pushMatrix();
        translate(0, -Z);
        rotate(radians(90+degree));
        mo3ian1.drawMo3ian();
        mo3ian2.drawMo3ian();
        popMatrix();
    }


    class Mo3ian {
        private float x1, y1, x2, y2;
        private double m;

        private int MIN_X1, MAX_X1, Y_INC;

        Mo3ian(int x1, int y1, int x2, int y2, int max_x) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.m = ((double)(x2-max_x))/(y2);
            MIN_X1 = 0;
            MAX_X1 = max_x;
            Y_INC = 1;
        }

        private void updateValues() {
            // make change to x1, y1;
            y1 -= Y_INC;
            x1 += m;
            if((int)x1 == MIN_X1){
                Y_INC *= -1;
            }
            else if((int)x1 == MAX_X1 || (int)x1 == -MAX_X1){
                m *= -1;
            }
        }

        private void drawMo3ian() {
            line(x1, y1, x2, y2);
            line(x1, y1, -x2, -y2);
            line(x2, y2, -x1, -y1);
            line(-x1, -y1, -x2, -y2);
        }
    }
}




