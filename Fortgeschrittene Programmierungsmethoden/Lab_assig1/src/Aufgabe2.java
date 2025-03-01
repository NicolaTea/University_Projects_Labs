public class Aufgabe2 {
    //1
    public  int maxim(int[] array){
        int max=array[0];
        for(int i=0;i<array.length;i++){
            if(array[i]>max){
                max=array[i];
            }
        }
        return max;

    }

    //2
    public  int minim(int[] array){
        int min=array[0];
        for(int i=0;i<array.length;i++){
            if(array[i]<min){
                min=array[i];
            }
        }
        return min;
    }

    //3
    public int suma_maxima(int[] array){
        int min=minim(array);
        int sum=0;
        for(int i=0;i<array.length;i++){
            sum+=array[i];
        }
        return sum-min;

    }

    //4
    public  int suma_minima(int[] array){
        int max=maxim(array);
        int sum=0;
        for(int i=0;i<array.length;i++){
            sum+=array[i];
        }
        return sum-max;
    }
}
