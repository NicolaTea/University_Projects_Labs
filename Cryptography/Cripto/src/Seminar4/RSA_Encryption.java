package Seminar4;

import java.util.Scanner;

public class RSA_Encryption {
    static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static long[] extendedEuclid(long a, long b) {
        long r0=a,r1=b;
        long s0=1,s1=0;
        long t0=0,t1=1;
        while (r1!=0) {
            long q=r0/r1;

            long r2=r0-q*r1;
            r0=r1;
            r1=r2;

            long s2=s0-q*s1;
            s0=s1;
            s1=s2;

            long t2= t0-q*t1;
            t0=t1;
            t1=t2;
        }
        return new long[]{r0, s0, t0};
    }


    public static long modInverse(long b, long phi) {
        long[] res=extendedEuclid(b, phi);
        if (res[0]!=1) {
            throw new RuntimeException("Inverse does not exist!");
        }
        long inv=res[1]%phi;
        return (inv<0)?inv+phi:inv;
    }


    public static long squareMultiply(long x, long c, long n) {
        long z=x%n;
        String binary=Long.toBinaryString(c);
        for (int i=1;i<binary.length();i++) {
            z=(z*z)%n;
            if (binary.charAt(i)=='1') {
                z=(z*x)%n;
            }
        }
        return z;
    }

    //convert characters into numbers
    public static long encode(String block) {
        long value=0;
        for (int i=0;i<block.length();i++) {
            int num=ALPHABET.indexOf(block.charAt(i));
            value=value*26+num;
        }
        return value;
    }

    //convert numbers into characters
    public static String decode(long value, int blockLength) {
        char[] result=new char[blockLength];
        for (int i=blockLength-1;i>=0;i--) {
            result[i]=ALPHABET.charAt((int)(value%26));
            value/=26;
        }
        return new String(result);
    }

    //Encryption
    public static String Encryption(int p, int q, int b, String plaintext, int blockLength) {
        long n=(long)p*q;
        plaintext=plaintext.toUpperCase().replaceAll("[^A-Z]", "");

        //padding
        while (plaintext.length() % blockLength!=0) {
            plaintext+="A";
        }

        StringBuilder cipher=new StringBuilder();
        for (int i=0;i<plaintext.length();i+=blockLength) {
            String block=plaintext.substring(i,i+blockLength);
            long m=encode(block);
            if (m>=n) {
                throw new RuntimeException("Block too large for n!");
            }
            long c=squareMultiply(m,b,n);
            cipher.append(c).append(" ");
        }
        return cipher.toString().trim();
    }

    //Decryption
    public static String Decryption(int p, int q, int a, String ciphertext, int blockLength) {
        long n=(long)p*q;
        StringBuilder plaintext=new StringBuilder();
        String[] parts=ciphertext.split("\\s+");
        for (String part:parts) {
            long c=Long.parseLong(part);
            long m=squareMultiply(c,a,n);
            plaintext.append(decode(m,blockLength));
        }

        return plaintext.toString();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int p=113;
        int q=101;
        int b=3533;
        long n=(long)p*q;
        long phi=(p-1)*(q-1);

        System.out.print("Enter block length (1 or 2): ");
        int blockLength=sc.nextInt();
        sc.nextLine();
        long gcd=extendedEuclid(b, phi)[0];
        System.out.println("gcd(b, phi)="+gcd);
        if (gcd!=1) {
            System.out.println("Invalid b!");
            return;
        }

        //private key
        long a=modInverse(b, phi);
        System.out.println("Private key a="+a);

        System.out.print("Enter plaintext: ");
        String text=sc.nextLine();
        String cipher=Encryption(p,q,b,text,blockLength);
        System.out.println("Ciphertext: "+cipher);
        String decrypted=Decryption(p,q,(int)a,cipher,blockLength);
        System.out.println("Decrypted text: "+decrypted);
    }
}
