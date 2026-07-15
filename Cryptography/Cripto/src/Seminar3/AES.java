package Seminar3;

import java.util.Arrays;

public class AES {

    private static final int Nb = 4;      //nr columns
    private static final int Nk = 4;      //key length
    private static final int Nr = 10;     //nr rounds

    //S-Box
    private static final int[] sbox = {
            0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
            0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
            0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
            0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
            0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
            0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
            0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
            0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
            0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
            0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
            0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
            0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
            0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
            0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
            0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
            0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
    };

    //Inverse S-Box
    private static final int[] invSbox = {
            0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB,
            0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB,
            0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E,
            0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25,
            0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92,
            0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84,
            0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06,
            0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B,
            0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73,
            0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E,
            0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B,
            0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4,
            0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F,
            0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF,
            0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61,
            0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D
    };

    //Round constants (Rcon)
    private static final int[] Rcon = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};

    //HEX BYTE
    private static byte hexToByte(String hex) {
        return (byte) Integer.parseInt(hex, 16);
    }

    public static byte[] hexToBytes(String hex) {
        if (hex.length()%2!=0) {
            throw new IllegalArgumentException("Hex string length must be even.");
        }
        byte[] bytes=new byte[hex.length() / 2];
        for (int i=0;i<bytes.length;i++) {
            bytes[i]=hexToByte(hex.substring(2*i, 2*i+2));
        }
        return bytes;
    }

    public static String bytesToHex(byte[] bytes) {
        StringBuilder sb=new StringBuilder();
        for (byte b:bytes) {
            sb.append(String.format("%02X", b));
        }
        return sb.toString();
    }

    //Key Expansion
    public static int[] keyExpansion(byte[] key) {
        int[] w=new int[Nb*(Nr+1)];
        for (int i=0;i<Nk;i++){
            w[i]=((key[4*i]&0xFF)<<24)|((key[4*i+1]&0xFF)<<16)
                    |((key[4*i+2]&0xFF)<<8)|(key[4*i+3]&0xFF);
        }
        for (int i=Nk;i<w.length;i++) {
            int temp=w[i-1];
            if (i%Nk==0)
                temp=subWord(rotWord(temp))^(Rcon[i/Nk - 1]<<24);
            w[i]=w[i-Nk]^temp;
        }
        return w;
    }

    //RotWord
    public static int rotWord(int word) {
        return ((word<<8))|((word>>>24)&0xFF);
    }

    //SubWord
    public static int subWord(int word) {
        int b0=sbox[(word>>>24)&0xFF];
        int b1=sbox[(word>>>16)&0xFF];
        int b2=sbox[(word>>>8)&0xFF];
        int b3=sbox[word&0xFF];
        return (b0<<24)|(b1<<16)|(b2<<8)|b3;
    }

    //Get Round Key
    private static byte[] getRoundKey(int[] w, int round) {
        byte[] rk=new byte[16];
        for (int c=0;c<4;c++) {
            int word=w[4*round + c];
            rk[4*c]=(byte)((word>>>24)&0xFF);
            rk[4*c+1]=(byte)((word>>>16)&0xFF);
            rk[4*c+2]=(byte)((word>>>8)&0xFF);
            rk[4*c+3]=(byte)(word&0xFF);
        }
        return rk;
    }

    private static void addRoundKey(byte[] s, byte[] rk) {
        for (int i=0;i<16;i++) {
            s[i]^=rk[i];
        }
    }


    //SUB BYTES
    private static void subBytes(byte[] s) {
        for (int i=0;i<16;i++) {
            s[i]=(byte) sbox[s[i]&0xFF];
        }
    }


    private static void invSubBytes(byte[] state) {
        for (int i=0;i<16;i++) {
            state[i]=(byte) invSbox[state[i]&0xFF];
        }
    }

    //SHIFT ROWS
    private static void shiftRows(byte[] s) {
        byte tmp;

        //row 1
        tmp=s[1];
        s[1]=s[5];
        s[5]=s[9];
        s[9]=s[13];
        s[13]=tmp;

        //row 2
        tmp=s[2];
        s[2]=s[10];
        s[10]=tmp;

        tmp=s[6];
        s[6]=s[14];
        s[14]=tmp;

        //row 3
        tmp=s[3];
        s[3]=s[15];
        s[15]=s[11];
        s[11]=s[7];
        s[7]=tmp;
    }

    private static void invShiftRows(byte[] s) {
        byte tmp;

        //row 1
        tmp=s[13];
        s[13]=s[9];
        s[9]=s[5];
        s[5]=s[1];
        s[1]=tmp;

        //row 2
        tmp=s[2];
        s[2]=s[10];
        s[10]=tmp;

        tmp=s[6];
        s[6]=s[14];
        s[14]=tmp;

        //row3
        tmp=s[3];
        s[3]=s[7];
        s[7]=s[11];
        s[11]=s[15];
        s[15]=tmp;
    }

    //Multiply in GF(2^8)
    private static int gfMult(int a, int b) {
        int res=0;
        for (int i=0;i<8;i++) {
            if ((b&1)!=0){
                res^=a;
            }
            boolean hi=(a & 0x80)!=0;
            a=(a<<1)&0xFF;
            if (hi){
                a^=0x1B;
            }
            b>>=1;
        }
        return res&0xFF;
    }

    //MIX COLUMNS
    private static void mixColumns(byte[] s) {
        for (int c=0;c<4;c++) {
            int i=c*4;

            int s0=s[i]&0xFF;
            int s1=s[i+1]&0xFF;
            int s2=s[i+2]&0xFF;
            int s3=s[i+3]&0xFF;

            s[i]=(byte)(gfMult(2,s0)^gfMult(3,s1) ^s2 ^s3);
            s[i+1]=(byte)(s0^gfMult(2,s1)^gfMult(3,s2)^s3);
            s[i+2]=(byte)(s0^s1^gfMult(2,s2)^gfMult(3,s3));
            s[i+3]=(byte)(gfMult(3,s0)^s1^s2^gfMult(2,s3));
        }
    }


    private static void invMixColumns(byte[] state) {
        for (int c=0;c<4;c++) {
            int i=4*c;

            int s0=state[i]&0xFF;
            int s1=state[i+1]&0xFF;
            int s2=state[i+2]&0xFF;
            int s3=state[i+3]&0xFF;

            state[i]=(byte)(gfMult(0x0e,s0)^gfMult(0x0b,s1)^gfMult(0x0d,s2)^gfMult(0x09,s3));
            state[i+1]=(byte)(gfMult(0x09,s0)^gfMult(0x0e,s1)^gfMult(0x0b, s2)^gfMult(0x0d,s3));
            state[i+2]=(byte)(gfMult(0x0d,s0)^gfMult(0x09,s1)^gfMult(0x0e, s2)^gfMult(0x0b,s3));
            state[i+3]=(byte)(gfMult(0x0b,s0)^gfMult(0x0d,s1)^gfMult(0x09, s2)^gfMult(0x0e,s3));
        }
    }

    public static byte[] encryptBlock(byte[] input, int[] expandedKey) {
        byte[] state=Arrays.copyOf(input, 16);

        System.out.println("\nEncryption start");
        System.out.println("Initial state:"+bytesToHex(state));

        //Round 0
        addRoundKey(state, getRoundKey(expandedKey, 0));
        System.out.println("After addRoundKey(0):"+bytesToHex(state));

        //Rounds 1..9
        for (int round=1;round<Nr;round++) {
            subBytes(state);
            System.out.println("After subBytes("+round+"):"+bytesToHex(state));
            shiftRows(state);
            System.out.println("After shiftRows("+round+"):"+bytesToHex(state));
            mixColumns(state);
            System.out.println("After mixColumns("+round+"):"+bytesToHex(state));
            addRoundKey(state, getRoundKey(expandedKey, round));
            System.out.println("After addRoundKey("+round+"):"+bytesToHex(state));
        }

        //Final round
        subBytes(state);
        System.out.println("After subBytes(final):"+bytesToHex(state));
        shiftRows(state);
        System.out.println("After shiftRows(final):"+bytesToHex(state));
        addRoundKey(state, getRoundKey(expandedKey, Nr));
        System.out.println("After addRoundKey(final):"+bytesToHex(state));
        System.out.println("---------------------------------------------\n");
        return state;
    }

    public static byte[] decryptBlock(byte[] input, int[] expandedKey) {
        byte[] state=Arrays.copyOf(input, 16);

        System.out.println("\nDecryption start");
        System.out.println("Initial state:"+bytesToHex(state));

        //Round initial
        addRoundKey(state, getRoundKey(expandedKey, Nr));
        System.out.println("After addRoundKey("+Nr+"):"+bytesToHex(state));

        //Rounds inverse
        for (int round=Nr-1;round>=1;round--) {
            invShiftRows(state);
            System.out.println("After invShiftRows("+round+"):"+bytesToHex(state));
            invSubBytes(state);
            System.out.println("After invSubBytes("+round+"):"+bytesToHex(state));
            addRoundKey(state, getRoundKey(expandedKey, round));
            System.out.println("After addRoundKey("+round+"): " + bytesToHex(state));
            invMixColumns(state);
            System.out.println("After invMixColumns("+round+"):"+bytesToHex(state));
        }

        //Final round
        invShiftRows(state);
        System.out.println("After invShiftRows(final):"+bytesToHex(state));
        invSubBytes(state);
        System.out.println("After invSubBytes(final):"+bytesToHex(state));
        addRoundKey(state, getRoundKey(expandedKey, 0));
        System.out.println("After addRoundKey(0):"+bytesToHex(state));
        System.out.println("----------------------------------------------------------\n");
        return state;
    }

    //ECB MODE
    public static byte[] addPadding(byte[] data) {
        int padLen=16-(data.length % 16);
        byte[] padded=Arrays.copyOf(data, data.length + padLen);
        for (int i=data.length;i<padded.length;i++){
            padded[i]=(byte) padLen;
        }
        return padded;
    }

    public static byte[] removePadding(byte[] data) {
        int padLen=data[data.length-1]&0xFF;
        return Arrays.copyOf(data, data.length-padLen);
    }


    public static byte[] ecbEncrypt(byte[] plaintext, byte[] key) {
        int[] ek=keyExpansion(key);

        //with padding
        //byte[] padded=addPadding(plaintext);

        //without padding
        int fullLength = (plaintext.length / 16) * 16;
        byte[] padded = new byte[fullLength];
        System.arraycopy(plaintext, 0, padded, 0, fullLength);

        byte[] out=new byte[padded.length];
        for (int i=0;i<padded.length;i+=16){
            System.arraycopy(encryptBlock(Arrays.copyOfRange(padded, i, i+16), ek), 0, out, i, 16);
        }
        return out;
    }


    public static byte[] ecbDecrypt(byte[] ciphertext, byte[] key) {
        int[] ek=keyExpansion(key);
        byte[] out=new byte[ciphertext.length];
        for (int i=0;i<ciphertext.length;i+=16){
            System.arraycopy(decryptBlock(Arrays.copyOfRange(ciphertext, i, i+16), ek), 0, out, i, 16);
        }
        //with padding
        //return removePadding(out);

        //without padding
        return out;
    }


    public static void main(String[] args) {
        String keyHex="00000000000000000000000000000000";
        //String plaintextHex="00112233445566778899AABBCCDDEEFF";
        String plaintextHex="00000000000000000000000000000000";
        byte[] key=hexToBytes(keyHex);
        byte[] plaintext=hexToBytes(plaintextHex);
        int[] expandedKey=keyExpansion(key);
        System.out.println("Single-block AES-128 test");
        byte[] ciphertext=encryptBlock(plaintext, expandedKey);
        byte[] decrypted=decryptBlock(ciphertext, expandedKey);
        System.out.println("Key:"+keyHex);
        System.out.println("Plaintext:"+plaintextHex);
        System.out.println("Ciphertext:"+bytesToHex(ciphertext));
        System.out.println("Decrypted:"+bytesToHex(decrypted));
        System.out.println("--------------------------------------------------");

        //ECB mode test
        String messageHex="00112233445566778899AABBCCDDEEFF" +
                "00111111111111111111111111111111";
        byte[] message=hexToBytes(messageHex);
        System.out.println("\nAES-128-ECB test");
        byte[] ecbCiphertext=ecbEncrypt(message, key);
        byte[] ecbDecrypted= ecbDecrypt(ecbCiphertext, key);
        System.out.println("Plaintext:"+messageHex);
        System.out.println("Ciphertext:"+bytesToHex(ecbCiphertext));
        System.out.println("Decrypted:"+bytesToHex(ecbDecrypted));

    }
}