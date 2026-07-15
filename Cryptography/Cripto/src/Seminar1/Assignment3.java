package Seminar1;
import java.util.Scanner;

public class Assignment3 {
    private static int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    private static String Encryption(int c11, int c12, int c21, int c22, String plaintext){
        int det=(c11*c22-c12*c21)%26;
        if(det<0){
            det+=26;
        }
        if(gcd(det,26)!=1){
            System.out.println("det(K) and 26 are not coprime");
            return"";
        }

        StringBuilder cipherText=new StringBuilder();
        plaintext=plaintext.toLowerCase().replaceAll("[^a-z]", "");
        if(plaintext.length()%2 != 0){
            plaintext+="z";
        }
        for(int i=0;i<plaintext.length();i+=2){
            int x1=plaintext.charAt(i)-'a';
            int x2=plaintext.charAt(i+1)-'a';
            int y1=(c11*x1+c12*x2)%26;
            int y2=(c21*x1+c22*x2)%26;
            if(y1 < 0){
                y1+=26;
            }
            if(y2 < 0){
                y2+=26;
            }
            cipherText.append((char)(y1+'a'));
            cipherText.append((char)(y2+'a'));
        }
        return cipherText.toString();
    }

    public static void main(String[] args){
        Scanner scanner= new Scanner(System.in);
        System.out.println("c11=");
        int c11 = scanner.nextInt();
        System.out.println("c12=");
        int c12 = scanner.nextInt();
        System.out.println("c21=");
        int c21 = scanner.nextInt();
        System.out.println("c22=");
        int c22 = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Plaintext:");
        String plaintext = scanner.nextLine();
        System.out.println("Ciphertext: " + Encryption(c11, c12, c21, c22, plaintext));
    }
}
