package Seminar4;

public class RSA_Hack {
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

    public static long[] factor(long n) {
        for (long i=2;i*i<=n;i++) {
            if (n%i==0) {
                return new long[]{i,n/i};
            }
        }
        return new long[]{1,n};
    }

    public static int[] parseCipher(String text) {
        String[] parts=text.split("\\s*,\\s*");
        int[] arr=new int[parts.length];
        for (int i=0;i<parts.length;i++) {
            arr[i]=Integer.parseInt(parts[i]);
        }
        return arr;
    }

    public static String HackRSA(int n, int b, String cipherText) {
        int[] cipher=parseCipher(cipherText);
        long[] pq=factor(n);
        long p=pq[0];
        long q=pq[1];
        long phi=(p-1)*(q-1);
        long a=modInverse(b,phi);

        StringBuilder result=new StringBuilder();
        for (int c:cipher) {
            long m=squareMultiply(c,a,n);
            result.append(ALPHABET.charAt((int)(m%26)));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        int n=18721;
        int b=25;
        String cipherText="365, 0, 4845, 14930, 2608, 2608, 0";
        String plain=HackRSA(n,b,cipherText);
        System.out.println("Recovered text: "+plain);
    }
}
