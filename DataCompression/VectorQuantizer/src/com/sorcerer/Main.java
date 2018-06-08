package com.sorcerer;
import processing.core.PApplet;
import processing.core.PImage;

import java.util.ArrayList;

public class Main extends PApplet {
    // img: the image to view
// img2: the image to edit and view
    PImage img, img2;


    private int codeBookSize = 64;
    public static int blockLingth = 5;


    public void settings(){
        // size of the canvas
        size(800, 400);
    }

    public void setup(){
        background (127);
        img = loadImage("C:\\Users\\mahmo\\Desktop\\dog.jpg");
        img.resize(400, 400);
        image(img, 0, 0);
        img2 = img.copy();

        //transform 1d vector of pixels into 2d matrix
        int matrix[][] = vectorToMatrix(img.pixels);

        // bit wising all the pixels, it returns the GRAY scale even if it's colored image
        pixelsBitWize(matrix);

        // cut the matrix into blocks 4*4 pixel each
        ArrayList<Block> blocks = cutTheMatrix(matrix);

        VectorQuantizer vq = new VectorQuantizer(blockLingth);
        CompressOutput co = vq.compress(blocks, codeBookSize);

        // get the decompressed 2d matrix
        int[][] decompressed = vq.decompress(co);

        // make it 1d again
        int[] reshaped_to_1d_vector = matrixToVector(decompressed);

        // bit wising again, and update pixels
        for(int i = 0; i < reshaped_to_1d_vector.length; i++){
            int x =  reshaped_to_1d_vector[i] * 3;
            img2.pixels[i] = ( ( ( x << 8 ) + x ) << 8 ) + x ;
        }

        // show image
        image(img2, 400, 0);
        noLoop();
    }

    public void draw(){
    }

    private int[] matrixToVector(int[][] matrix){
        int vector[] = new int[160000];
        int index = 0;
        for(int i = 0; i < 400; i++){
            for(int j = 0; j < 400; j++){
                vector[ index++ ] = matrix[i][j];
            }
        }
        return vector;
    }

    private int[][] vectorToMatrix(int[] pixels){
        int matrix[][] = new int[400][400];
        int x = 0;
        int y = 0;
        for(int i = 0; i < 160000; i++){
            matrix[y][x] = pixels[i];
            x++;
            y += x/400;
            x %= 400;
        }
        return matrix;
    }

    private void pixelsBitWize(int matrix[][]){
        for(int i = 0; i < 400; i++)
        {
            for(int j = 0; j < 400; j ++) {
                int x = matrix[i][j] & 0xff;
                x = (((x >> 16) & 0xff) + ((x >> 8) & 0xff) + (x & 0xff)) / 3;
                matrix[i][j] = x;
            }
        }
    }

    private ArrayList<Block> cutTheMatrix(int matrix[][]){
        ArrayList<Block> blocks = new ArrayList<Block>();
        for(int i = 0; i < 400/blockLingth; i++)
        {
            for(int j = 0; j < 400/blockLingth; j++) {
                Block b = new Block(blockLingth);
                int bi = 0; int bj = 0;
                for(int r = i; r < i+blockLingth; r++){
                    for(int c = j; c < j+blockLingth; c++){
                        b.matrix[bi++][bj] = matrix[i*(blockLingth-1)+r][j*(blockLingth-1)+c];
                    }
                    bi = 0;
                    bj++;
                }
                blocks.add(b);
            }
        }
        return blocks;
    }

}

