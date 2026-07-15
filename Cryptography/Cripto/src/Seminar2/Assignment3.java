package Seminar2;

import java.util.Scanner;

public class Assignment3 {
    static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";

    static char caesarEncrypt(char currChar) {
        int cipherVal=ALPHABET.indexOf(currChar);
        int encryptedVal=(cipherVal+3)%26;
        return ALPHABET.charAt(encryptedVal);
    }

    public static void encodeMessage(String message, int bits) {
        if (message==null || message.trim().isEmpty()) {
            System.out.println("Message is empty.");
            return;
        }

        message=message.toLowerCase();
        int levels=(int)Math.pow(2,bits); //number of discrete levels for ADC
        double step=2.0/levels;           //voltage diff between two consecutive levels
        double Vmin=-1.0;                 //minimum voltage
        System.out.println("Encrypted and PCM signal:");

        for (char currChar:message.toCharArray()) {
            if (!Character.isLetter(currChar)){
                continue;
            }
            char encryptedChar=caesarEncrypt(currChar);
            int level=ALPHABET.indexOf(encryptedChar);
            double voltage=Vmin+level*step;
            String binary=String.format("%5s", Integer.toBinaryString(level)).replace(' ','0');

            System.out.println("Letter:"+currChar+"=>Encrypted:"+encryptedChar
                    + ";Level:"+level
                    + ";Voltage:"+String.format("%.4f",voltage)+" V"
                    + ";Binary:" +binary);
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter message:");
        String message=sc.nextLine();
        int bits=5;
        encodeMessage(message, bits);
        sc.close();
    }
}
