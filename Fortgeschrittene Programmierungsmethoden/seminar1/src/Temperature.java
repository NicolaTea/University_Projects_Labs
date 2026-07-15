public class Temperature {
    public int[] temperatures;
    public Temperature(int[] temperatures){
        this.temperatures=temperatures;
    }

    public double average(){
        double sum=0;
        for(int i=0;i< temperatures.length;i++){
            sum+=temperatures[i];

        }
        return sum/temperatures.length;
    }

    public int[] maxDiff(){
        int maxdif=0;
        int index=0;
        for(int i=0;i<temperatures.length-1;i++){
            if(temperatures[i+1]-temperatures[i]>maxdif){
                index=i;
                maxdif=temperatures[i+1]-temperatures[i];
            }
            if(temperatures[i]-temperatures[i+1]>maxdif){
                index=i;
                maxdif=temperatures[i]-temperatures[i+1];
            }
        }
        return new int[]{index+1,index+2};
    }

    public int min() {
        int min = temperatures[0];
        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] < min) {
                min = temperatures[i];
            }
        }
        return min;
    }

    public int max() {
        int max = temperatures[0];
        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] > max) {
                max = temperatures[i];
            }
        }

        return max;
    }

    public void print(){
        String tagen="Tag: ";
        String temperaturen="Temperatur: ";
        int differenz=temperaturen.length()-tagen.length();
        for(int i=0;i<differenz;i++){
            tagen+=" ";
        }
        for(int i=0;i<temperatures.length;i++){
            String tag=String.valueOf(i+1);
            String temp=String.valueOf(temperatures[i]);
            if (tag.length() > temp.length()) {
                for (int ii = 0; ii < tag.length() - temp.length(); ii++) {
                    temperaturen += " ";
                }
            } else if (temp.length() > tag.length()) {
                for (int ii = 0; ii < temp.length() - tag.length(); ii++) {
                    tagen += " ";
                }
            }
            temperaturen += " ";
            tagen += " ";

            temperaturen += temp;
            tagen += tag;

        }
        System.out.println(tagen);
        System.out.println(temperaturen);

    }
}
