package com.sorcerer;

import java.util.Random;

public class FakeDataGenerator {
    private static Random random = new Random();
    public static String generate(int length){
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < length; i++){
            sb.append( (char) (random.nextInt('z'-'a')+'a'));
        }
        return sb.toString();
    }
}
