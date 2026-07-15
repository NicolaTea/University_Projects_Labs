package Seminar5;

import java.awt.image.BufferedImage;
import java.io.File;
import java.security.MessageDigest;
import java.security.SecureRandom;
import javax.imageio.ImageIO;

public class Steganography {
    static SecureRandom random=new SecureRandom();


    public static long squareMultiply(long x, long c, long n) {
        long z=1;
        x=x%n;
        while (c>0) {
            if ((c&1)==1) {
                z=(z*x)%n;
            }
            x=(x*x)%n;
            c>>=1;
        }
        return z;
    }


    public static long verify_beta(long alpha, long a, long p) {
        return squareMultiply(alpha,a,p);
    }


    public static long[] extendedEuclid(long a, long b) {
        long r0=a,r1=b;
        long s0=1,s1=0;

        while (r1!=0) {
            long q=r0/r1;

            long r=r0-q*r1;
            r0=r1;
            r1=r;

            long s=s0-q*s1;
            s0=s1;
            s1=s;
        }
        return new long[]{r0, s0};
    }

    public static long modInverse(long a, long m) {
        long[] res=extendedEuclid(a,m);
        long inv=res[1]%m;
        return (inv<0)?inv+m:inv;
    }


    public static String salt(String msg) {
        byte[] s=new byte[4];
        random.nextBytes(s);
        StringBuilder sb=new StringBuilder();
        for (byte b:s) {
            sb.append(String.format("%02x",b));
        }
        return msg+sb;
    }

    public static String sha256(String msg) throws Exception {
        MessageDigest md=MessageDigest.getInstance("SHA-256");
        byte[] hash=md.digest(msg.getBytes());
        StringBuilder sb=new StringBuilder();
        for (byte b:hash) {
            sb.append(String.format("%02x",b));
        }
        return sb.toString();
    }


    public static String hexToBinary(String hex) {
        StringBuilder bin=new StringBuilder();

        for (int i=0;i< hex.length();i++) {
            String b=Integer.toBinaryString(Integer.parseInt(hex.substring(i, i+1), 16));
            while (b.length()<4){
                b="0"+b;
            }
            bin.append(b);
        }
        return bin.toString();
    }


    public static void hideHash(String hash, String input, String output) throws Exception {
        BufferedImage img=ImageIO.read(new File(input));
        String bin=hexToBinary(hash);
        int k=0;

        outer:
        for (int y=0;y<img.getHeight();y++) {
            for (int x=0;x<img.getWidth();x++) {
                if (k>=bin.length()){
                    break outer;
                }
                int pixel=img.getRGB(x, y);
                int r=(pixel>>16)&255;
                int g=(pixel>>8)&255;
                int b=pixel & 255;

                if (k<bin.length()){
                    r=(r&0xFE)|(bin.charAt(k++)-'0');
                }
                if (k<bin.length()){
                    g=(g & 0xFE)|(bin.charAt(k++)-'0');
                }
                if (k<bin.length()){
                    b=(b & 0xFE)|(bin.charAt(k++)-'0');
                }

                int newPixel=(r<<16)|(g<<8)|b;
                img.setRGB(x, y, newPixel);
            }
        }
        ImageIO.write(img, "png", new File(output));
    }

    public static String extractHash(String path, int bits) throws Exception {
        BufferedImage img=ImageIO.read(new File(path));
        StringBuilder bin=new StringBuilder();
        int count=0;

        outer:
        for (int y=0;y<img.getHeight();y++) {
            for (int x=0;x<img.getWidth();x++) {
                if (count>=bits){
                    break outer;
                }
                int pixel=img.getRGB(x, y);
                int r=(pixel>>16)&255;
                int g=(pixel>>8)&255;
                int b=pixel&255;

                if (count<bits){
                    bin.append(r&1); count++;
                }
                if (count<bits){
                    bin.append(g&1); count++;
                }
                if (count<bits){
                    bin.append(b&1);count++;
                }
            }
        }

        StringBuilder hex=new StringBuilder();
        for (int i=0;i<bin.length();i+=4) {
            String nibble=bin.substring(i,i+4);
            hex.append(Integer.toHexString(Integer.parseInt(nibble, 2)));
        }
        return hex.toString();
    }


    public static void main(String[] args) throws Exception {
        long p=107;
        long alpha=122503;
        long a=10;
        long k=45;
        String message="B";

        //1.beta
        long beta=verify_beta(alpha,a,p);
        System.out.println("Beta="+beta);

        //2.signature(ElGamal)
        long gamma=squareMultiply(alpha,k,p);
        long kInv=modInverse(k, p-1);
        long m=message.charAt(0);
        long delta=(m-a*gamma)%(p-1);
        if (delta<0){
            delta+=(p-1);
        }
        delta=(delta*kInv)%(p-1);
        String signature=gamma+""+delta;
        System.out.println("Signature=("+gamma+","+delta+")");

        // 3.salt+hash
        String salted=salt(signature);
        System.out.println("Salted="+salted);
        String hash=sha256(salted);
        System.out.println("Hash="+hash);

        //4.hide in image
        hideHash(hash,
                "src/Seminar5/image.jpeg",
                "src/Seminar5/image_new.jpeg");
        System.out.println("Hash hidden in image_new.png");

        //5.extract
        String extracted=extractHash(
                "src/Seminar5/image_new.jpeg",
                hash.length()*4
        );
        System.out.println("Extracted="+extracted);

        //6.verify
        boolean ok=extracted.equals(hash);
        System.out.println("Verify="+ok);
    }
}