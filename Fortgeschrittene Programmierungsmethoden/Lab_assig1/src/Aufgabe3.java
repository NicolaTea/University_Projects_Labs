public class Aufgabe3 {
    //1
    public int[] suma(int[] n1,int[] n2){
        int[] result= new int[n1.length+1];
        int carry=0;
        for(int i=n1.length-1;i>=0;i--){
            int sum=n1[i]+n2[i]+carry;
            result[i+1]=sum%10;
            carry=sum/10;
        }
        result[0]=carry;
        if(result[0]==0){
            int[] new_result=new int[n1.length];
            for(int i=0;i<n1.length;i++){
                new_result[i]=result[i+1];
            }
            return new_result;
        }
        return result;
    }

    //2
    public int[] diferenta(int n1[], int[] n2){
        int[] result=new int[n1.length];
        int borrow=0;
        for(int i=n1.length-1;i>=0;i--){
            int diff=n1[i]-n2[i]-borrow;
            if(diff<0){
                diff+=10;
                borrow=1;
            }else{
                borrow=0;
            }
            result[i]=diff;
        }
        int leading_zero=0;
        while(leading_zero<result.length && result[leading_zero]==0){
            leading_zero++;
        }
        if(leading_zero== result.length){
            return new int[]{0};
        }
        int[] new_result = new int[result.length - leading_zero];
        for (int i = 0; i < new_result.length; i++) {
            new_result[i] = result[leading_zero + i];
        }

        return new_result;



    }

    //3
    public int[] mul(int[] number,int cf){
        int carry=0;
        int[] result=new int[number.length];

        boolean is_negativ=(cf<0);
        cf=Math.abs(cf);

        //parcurgere de la dreapta la stanga
        for(int i=number.length-1;i>=0;i--){
            int produs=number[i]*cf+carry;

            result[i]=produs%10;
            carry=produs/10;

        }
        if(carry>0){
            int[] extensie_result=new int[number.length+1];
            extensie_result[0]=carry;
            for(int i=0;i<number.length;i++){ //copiem cifrele in noul array
                extensie_result[i+1]=result[i];
            }
            return extensie_result;
        }

        if(is_negativ){
            result[0]=-result[0];
        }

        return result;
    }

    //4
    public int[] div(int[] number,int cf){
        int remainder=0;
        int[] result=new int[number.length];

        boolean is_negativ=(cf<0);
        cf=Math.abs(cf);

        //parcurgem fiecare cifra a nr
        for(int i=0;i<number.length;i++){
            int current=remainder*10+number[i];
            result[i]=current/cf;
            remainder=current%cf;
        }

        int leading_zero=0;
        while(leading_zero<result.length && result[leading_zero]==0){
            leading_zero++;
        }

        int[] final_result=new int[result.length-leading_zero];
        for(int i=0;i<final_result.length;i++){
            final_result[i]=result[leading_zero+i];
        }

        if(is_negativ&&final_result.length>0){
            final_result[0]=-final_result[0];
        }

        return final_result;

    }

}
