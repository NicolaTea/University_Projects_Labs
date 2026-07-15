package Seminar1;

import java.util.Scanner;

public class Assignment2_2 {
    private static int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    private static int modInverse(int a,int m){
        for(int i=1;i<m;i++){
            if((a*i)%m==1){
                return i;
            }
        }
        return -1;
    }

    private static String Decryption(int a, int b, String ciphertext){
        StringBuilder plaintext=new StringBuilder();
        int aInverse=modInverse(a,26);
        for(int i=0;i<ciphertext.length();i++){
            char currChar=ciphertext.charAt(i);
            if(Character.isLetter(currChar)){
                char base=Character.isUpperCase(currChar)? 'A':'a';
                int cipherVal=currChar-base;
                int plainVal=(((aInverse*(cipherVal-b))%26)+26)%26;
                if(plainVal<0){
                    plainVal+=26;
                }
                char decrypted=(char)(plainVal+base);
                plaintext.append(decrypted);

            }
        }
        return plaintext.toString();
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
        System.out.println("Ciphertext:");
        String cipherText=scanner.nextLine();
        System.out.println("Plaintext: "+Decryption(a,b,cipherText));


    }
}
