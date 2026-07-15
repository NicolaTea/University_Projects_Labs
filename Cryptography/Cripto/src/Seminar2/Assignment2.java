package Seminar2;

import java.util.Scanner;

public class Assignment2 {
    static final int[] VALID_A = {1,3,5,7,9,11,15,17,19,21,23,25};

    static double scoreText(String text) {
        text=text.toLowerCase();
        double score=0;
        String monograms="etaoin";
        String[] digrams={ "th","he","in","er","an","re","on","at","ss","ee","tt"};
        String[] trigrams={"the","and","ing","her","ent","tio","ati"};
        String[] words = {"it","is","to","of","a","i"};

        //monograms
        for (char curChar:text.toCharArray()) {
            if (monograms.indexOf(curChar)!=-1) {
                score+=2;
            }
        }

       //digrams
        for (String pattern:digrams) {
            int pos=text.indexOf(pattern);
            while (pos!=-1) {
                score+=10;
                pos=text.indexOf(pattern, pos + 1);
            }
        }

        //trigrams
        for (String pattern : trigrams) {
            int pos=text.indexOf(pattern);
            while (pos!=-1) {
                score+=20;
                pos=text.indexOf(pattern, pos + 1);
            }
        }

        //common words
        for (String w:words) {
            int pos=text.indexOf(w);
            while (pos!=-1) {
                score+=15;
                pos=text.indexOf(w, pos + 1);
            }
        }

        // rare letters
        if (text.contains("q")){
            score-=5;
        }
        if (text.contains("z")){
            score-=5;
        }
        if (text.contains("x")){
            score-=3;
        }

        return score;
    }

    private static int modInverse(int a,int m){
        for(int i=1;i<m;i++){
            if((a*i)%m==1){
                return i;
            }
        }
        return -1;
    }

    static String decryptAffine(String cipher, int a, int b) {
        int aInverse=modInverse(a,26);
        StringBuilder plain=new StringBuilder();
        for (char currChar:cipher.toCharArray()) {
            if (Character.isLetter(currChar)) {
                char base=Character.isUpperCase(currChar) ? 'A' : 'a';
                int cipherVal=currChar-base;
                int decryptedVal=(aInverse*(cipherVal-b+26))%26;
                plain.append((char)(decryptedVal+base));
            }
        }

        return plain.toString();
    }

    public static void HackAffine(String cipherText) {
        cipherText=cipherText.toLowerCase();
        double bestScore=-1;
        String bestPlaintext="";
        int keyA=0;
        int keyB=0;

        for (int a:VALID_A) {
            for (int b=0;b<26;b++) {
                String plainText=decryptAffine(cipherText,a,b);
                double score=scoreText(plainText);
                if (score>bestScore) {
                    bestScore=score;
                    bestPlaintext=plainText;
                    keyA=a;
                    keyB=b;
                }
            }
        }

        System.out.println("Best result:");
        System.out.println("Plaintext:"+bestPlaintext);
        System.out.println("Key a="+keyA+",b="+keyB);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter ciphertext:");
        String cipherText=sc.nextLine();
        HackAffine(cipherText);
        sc.close();
    }
}