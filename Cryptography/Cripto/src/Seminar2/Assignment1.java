package Seminar2;

import java.util.Scanner;

public class Assignment1 {
    static final String ALPHABET = "012345abcdefghijklmnopqrstuvwxyz";

    static int scoreText(String text) {
        text=text.toLowerCase();
        int score=0;
        String monograms="etaoin";
        String[] digrams={ "th","he","in","er","an","re","on","at","ss","ee","tt"};
        String[] trigrams={"the","and","ing","her","ent","tio","ati"};

        //monograms
        for (char currChar:text.toCharArray()) {
            if (monograms.indexOf(currChar)!=-1){
                score+=1;
            }
        }

        //digrams
        for (String pattern:digrams) {
            int pos=text.indexOf(pattern);
            while (pos!=-1) {
                score+=3;
                pos=text.indexOf(pattern, pos + 1);
            }
        }

        //trigrams
        for (String pattern:trigrams) {
            int pos=text.indexOf(pattern);
            while (pos!=-1) {
                score+=5;
                pos=text.indexOf(pattern, pos + 1);
            }
        }

        return score;
    }


    public static String decrypt(String ciphertext, int key) {
        int m=ALPHABET.length();
        StringBuilder plainText=new StringBuilder();
        for (char currChar:ciphertext.toCharArray()) {
            int cipherVal=ALPHABET.indexOf(currChar);
            if (cipherVal==-1) {
                continue;
            }
            int decryptedVal=(cipherVal-key+m)%m;
            char decrypted=ALPHABET.charAt(decryptedVal);
            plainText.append(decrypted);
        }

        return plainText.toString();
    }

    public static void HackShift(String ciphertext) {
        ciphertext=ciphertext.toLowerCase();
        int m=ALPHABET.length();
        int bestKey=0;
        int bestScore=-1;
        String bestPlaintext ="";

        for (int key=0;key<m;key++) {
            String plainText=decrypt(ciphertext, key);
            int score=scoreText(plainText);

            System.out.println("key="+key);
            System.out.println("plaintext:"+plainText);
            System.out.println("score:"+score);
            System.out.println();

            if (score>bestScore) {
                bestScore=score;
                bestKey=key;
                bestPlaintext=plainText;
            }
        }

        System.out.println("Best result:");
        System.out.println("Key:"+bestKey);
        System.out.println("Plaintext:"+bestPlaintext);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter ciphertext:");
        String ciphertext=sc.nextLine();
        HackShift(ciphertext);
        sc.close();
    }
}