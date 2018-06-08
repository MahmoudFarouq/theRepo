
package com.multimedia;
import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;


public class IOForm {
    public JPanel panel1;
    private JButton openFileButton;
    private JButton compressButton;
    private JTextArea textArea1;
    private JButton decompressButton;
    private String filePath;

    private lzw _lzw;


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
                    String filepath = f.getPath();
                    try(BufferedReader br = Files.newBufferedReader(Paths.get(filepath))){
                        String s1 = "",s2 = "";
                        while((s1 = br.readLine()) != null){
                            s2 += s1 + "\n";
                        }
                        textArea1.setText(s2);
                    }catch (Exception ex) {ex.printStackTrace();  }
                }
            }
        });
        compressButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {
                super.mouseClicked(mouseEvent);
                textArea1.setText("");
                if(_lzw == null) {
                    _lzw = new lzw();
                }
                try {
                    _lzw.Compress(filePath, textArea1);
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
                if(_lzw == null) {
                    _lzw = new lzw();
                }
                try {
                    _lzw.Decompress(filePath, textArea1);
                }catch (IOException ex){
                    ex.printStackTrace();
                }
            }
        });
    }


}
