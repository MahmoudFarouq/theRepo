package com.sorcerer;

import processing.core.PApplet;
import processing.core.PImage;

import java.util.ArrayList;

public class Main extends PApplet{

    PImage img, img2;
    Quantizer q;

    public void settings()
    {
        size(800, 400);

    }

    public void setup(){
        background (127);
        img = loadImage("C:\\Users\\mahmo\\Desktop\\dog.jpg");
        img.resize(400, 400);
        image(img, 0, 0);
        //img.filter(GRAY);
        img2 = img.copy();
        q = new Quantizer();
        for(int i = 0; i < img.pixels.length; i++)
        {
            int x = img.pixels[i] & 0xff;
            x = ( ((x >> 16 ) & 0xff) + ((x >> 8) & 0xff) + (x & 0xff) ) / 3;
            q.pixelsList.add( x );
        }
        q.numberOfBits = 5 ;
        CompressOutput co = q.compress();

        ArrayList<Integer> output = q.decompress(co);
        for(int i = 0; i < output.size(); i++){
            int x =  output.get( i ) * 3;
            img2.pixels[i] = ( ( ( x << 8 ) + x ) << 8 ) + x ;
        }

        image(img2, 400, 0);
        noLoop();
    }

    public void draw(){
    }
}
