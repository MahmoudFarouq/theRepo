package com.multimedia;

import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        AHC ahc = new AHC();
        try {
            String stream = "There are too many people today who instead of feeling hurt are acting out their hurt; instead of acknowledging pain, they're inflicting pain on others. Rather than risking feeling disappointed, they're choosing to live disappointed. Emotional stoicism is not badassery. Blustery posturing is not badassery. Swagger is not badassery. Perfection is about the furthest thing in the world from badasser";
            String s = ahc.Compress( stream );
            System.out.println(s);
            String dec = ahc.Decompress(s);
            System.out.println( dec.equals(stream) );
            System.out.println( (s.length()/8)+"/"+stream.length() );
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }
}