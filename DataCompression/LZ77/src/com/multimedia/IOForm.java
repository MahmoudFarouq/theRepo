package com.multimedia;

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class IOForm{
    public JPanel panel1;
    private JButton openFileButton;
    private JButton compressButton;
    private JTextArea textArea1;
    private JButton decompressButton;
    private String filePath;

    private lz77 _lz77;


    public IOForm() {
        openFileButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {
                super.mouseClicked(mouseEvent);
                textArea1.setText("");
                JFileChooser fc=new JFileChooser();
                int i = fc.showOpenDialog(mouseEvent.getComponent());
                if(i == JFileChooser.APPROVE_OPTION){
                    File f = fc.getSelectedFile();
                    filePath = f.getPath();
                    String filepath=f.getPath();
                    try{
                        BufferedReader br=new BufferedReader(new FileReader(filepath));
                        String s1="",s2="";
                        while((s1=br.readLine())!=null){
                            s2+=s1+"\n";
                        }
                        textArea1.setText(s2);
                        br.close();
                    }catch (Exception ex) {ex.printStackTrace();  }
                }
            }
        });
        compressButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {
                super.mouseClicked(mouseEvent);
                textArea1.setText("");
                if(_lz77 == null) {
                    _lz77 = new lz77();
                }
                try {
                    _lz77.Compress(filePath, textArea1);
                }catch (IOException ex){
                    ex.printStackTrace();
                }

            }
        });

        decompressButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {
                super.mouseClicked(mouseEvent);
                textArea1.setText("");
                if(_lz77 == null) {
                    _lz77 = new lz77();
                }
                try {
                    _lz77.Decompress(filePath, textArea1);
                }catch (IOException ex){
                    ex.printStackTrace();
                }
            }
        });
    }


}
