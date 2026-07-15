package Seminar1;

import java.util.Scanner;

public class Assignment1 {
    private static String Decryption(int Key, String ciphertext){
        StringBuilder plainText=new StringBuilder();
        for(int i=0;i<ciphertext.length();i++){
            char currChar=ciphertext.charAt(i);
            if(Character.isLetter(currChar)){
                char base=Character.isUpperCase(currChar) ? 'A':'a';
                int cipherVal=currChar-base;
                int decryptedVal=(cipherVal-Key)%26;
                if(decryptedVal <0){
                    decryptedVal+=26;
                }
                char decrypted=(char)(decryptedVal+base);
                plainText.append(decrypted);
            }
        }
        return plainText.toString();
    }

    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.print("Choose K=");
        int key=scanner.nextInt();
        scanner.nextLine();
        System.out.print("The ciphertext is:");
        String ciphertext=scanner.nextLine();
        System.out.println("Plaintext: " + Decryption(key, ciphertext));
        scanner.close();
    }
}
