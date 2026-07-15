package Seminar1;

import java.util.Scanner;

public class Assignment2_1 {
    private static int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    private static String Encryption(int a, int b, String plaintext) {
        StringBuilder ciphertext=new StringBuilder();
        for (int i=0;i<plaintext.length();i++) {
            char currChar=plaintext.charAt(i);
            if (Character.isLetter(currChar)) {
                char base=Character.isUpperCase(currChar) ? 'A' : 'a';
                int cipherVal=currChar-base;
                int encryptedVal=(((a*cipherVal+b)%26)+26)%26;
                char encrypted=(char)(encryptedVal+base);
                ciphertext.append(encrypted);
            }
        }
        return ciphertext.toString();
    }

    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.println("a=");
        int a=scanner.nextInt();
        System.out.println("b=");
        int b=scanner.nextInt();
        scanner.nextLine();
        if(gcd(a,26)!=1){
            System.out.println("a and 26 are not coprime.");
            return;
        }
        System.out.println("Plaintext:");
        String plainText=scanner.nextLine();
        System.out.println("Ciphertext: "+ Encryption(a,b,plainText));
    }
}
