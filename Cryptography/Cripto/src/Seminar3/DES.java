package Seminar3;

import java.util.Scanner;

public class DES {
    //Initial Permutation
    private static final int[] IP = {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17,  9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
    };

    //Final Permutation
    private static final int[] FP = {
            40,  8, 48, 16, 56, 24, 64, 32,
            39,  7, 47, 15, 55, 23, 63, 31,
            38,  6, 46, 14, 54, 22, 62, 30,
            37,  5, 45, 13, 53, 21, 61, 29,
            36,  4, 44, 12, 52, 20, 60, 28,
            35,  3, 43, 11, 51, 19, 59, 27,
            34,  2, 42, 10, 50, 18, 58, 26,
            33,  1, 41,  9, 49, 17, 57, 25
    };

    //Expansion function E
    private static final int[] E = {
            32,  1,  2,  3,  4,  5,
            4,  5,  6,  7,  8,  9,
            8,  9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32,  1
    };

    //S-Boxes
    private static final int[][][] S_BOX = {
            {   //S1
                    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
            },
            {   //S2
                    {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                    {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                    {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                    {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
            },
            {   //S3
                    {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                    {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                    {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                    {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
            },
            {   //S4
                    {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                    {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                    {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                    {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
            },
            {   //S5
                    {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
            },
            {   //S6
                    {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
            },
            {   //S7
                    {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
            },
            {   //S8
                    {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
            }
    };

    //Permutation P
    private static final int[] P = {
            16,  7, 20, 21,
            29, 12, 28, 17,
            1, 15, 23, 26,
            5, 18, 31, 10,
            2,  8, 24, 14,
            32, 27,  3,  9,
            19, 13, 30,  6,
            22, 11,  4, 25
    };

    //Key expansion PC1
    private static final int[] PC1 = {
            57,49,41,33,25,17,9,
            1,58,50,42,34,26,18,
            10, 2,59,51,43,35,27,
            19,11, 3,60,52,44,36,
            63,55,47,39,31,23,15,
            7,62,54,46,38,30,22,
            14, 6,61,53,45,37,29,
            21,13, 5,28,20,12, 4
    };

    //Key expansion PC2
    private static final int[] PC2 = {
            14,17,11,24, 1, 5,
            3,28,15, 6,21,10,
            23,19,12, 4,26, 8,
            16, 7,27,20,13, 2,
            41,52,31,37,47,55,
            30,40,51,45,33,48,
            44,49,39,56,34,53,
            46,42,50,36,29,32
    };

    //Left Shifts
    private static final int[] SHIFTS = {
            1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
    };

    static String[] roundKeys = new String[16];

    static String xor(String a, String b) {
        StringBuilder r=new StringBuilder();
        for (int i=0;i<a.length();i++){
            r.append(a.charAt(i)==b.charAt(i)?'0':'1');
        }
        return r.toString();
    }

    static String permute(String in, int[] table) {
        StringBuilder out=new StringBuilder();
        for (int i:table){
            out.append(in.charAt(i-1));
        }
        return out.toString();
    }

    static String shiftLeft(String s, int n) {
        return s.substring(n)+s.substring(0, n);
    }

    static String hexToBin(String hex) {
        StringBuilder bin=new StringBuilder();
        for (char c:hex.toCharArray()){
            bin.append(String.format("%4s", Integer.toBinaryString(Integer.parseInt("" + c, 16))).replace(' ', '0'));
        }
        return bin.toString();
    }

    static String binToHex(String bin) {
        StringBuilder hex=new StringBuilder();
        for (int i=0;i<bin.length();i+=4){
            hex.append(Integer.toHexString(Integer.parseInt(bin.substring(i, i + 4), 2)).toUpperCase());
        }
        return hex.toString();
    }

    //Key generation
    static void generateKeys(String keyHex) {
        String key=permute(hexToBin(keyHex), PC1);
        String C=key.substring(0, 28);
        String D=key.substring(28);

        for (int i=0;i<16;i++) { //we generate our 16 keys
            C=shiftLeft(C,SHIFTS[i]);
            D=shiftLeft(D,SHIFTS[i]);
            roundKeys[i]=permute(C+D,PC2);
        }
    }

    //Feistel
    static String feistel(String R, String K) {
        String expanded=permute(R, E);
        String x=xor(expanded, K);

        StringBuilder out=new StringBuilder();
        for (int i=0;i<8;i++) { //for every S-box(8)
            String block=x.substring(i*6,i*6+6);
            int row=Integer.parseInt("" +block.charAt(0)+block.charAt(5), 2);
            int col=Integer.parseInt(block.substring(1, 5), 2);
            out.append(String.format("%4s", Integer.toBinaryString(S_BOX[i][row][col])).replace(' ', '0'));
        }
        return permute(out.toString(), P);
    }

    //Block Encryption
    static String encryptBlock(String block) {
        block=permute(block, IP);
        String L=block.substring(0, 32);
        String R=block.substring(32);

        for (int i=0;i<16;i++) { //for every round(16)
            String temp=R;
            R=xor(L, feistel(R, roundKeys[i]));
            L=temp;
            System.out.println("Round " + (i+1)+" => L="+binToHex(L)+" R="+binToHex(R));

        }
        System.out.println("---------------------------------");
        return permute(R + L, FP);
    }


    //CBC-Cipher Block Chain
    static String encryptCBC(String text, String key) {
        generateKeys(key);
        byte[] textBytes=text.getBytes();


        int fullLength=(textBytes.length/8)*8;
        byte[] padded = new byte[fullLength];
        System.arraycopy(textBytes, 0, padded, 0, fullLength);

        String IV="0000000000000000000000000000000000000000000000000000000000000000";
        String prev=IV;

        StringBuilder result=new StringBuilder();
        for (int i=0;i<padded.length;i+=8) { //for every block of 8 bytes
            byte[] blockBytes=new byte[8];
            System.arraycopy(padded, i, blockBytes, 0, 8);
            String blockHex="";
            for (byte b:blockBytes){
                blockHex+=String.format("%02X", b);
            }

            String blockBin=hexToBin(blockHex);
            blockBin=xor(blockBin, prev);
            String enc=encryptBlock(blockBin);
            prev=enc;
            result.append(binToHex(enc));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String key="3B3898371520F75E";
        String plaintext="DES algoritm is better than classical algorithms";
        String cipher=encryptCBC(plaintext, key);
        System.out.println("Plaintext:"+plaintext);
        System.out.println("Key(hex):"+key);
        System.out.println("Ciphertext(hex):"+cipher);
    }
}
