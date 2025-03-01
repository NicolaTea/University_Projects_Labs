public class Aufgabe4 {
        //1
        public  int tastatura_ieftina(int[] tastaturi){
            int min=tastaturi[0];
            for(int tastatura:tastaturi){
                if(tastatura<min){
                    min=tastatura;
                }
            }
            return min;
        }

        //2
        public  int gagdet_scump(int [] tastaturi, int[] usbs){
            int max=tastaturi[0];
            for(int tastatura: tastaturi){
                if(tastatura>max){
                    max=tastatura;
                }
            }
            for(int usb:usbs){
                if(usb>max){
                    max=usb;
                }
            }
            return max;
        }

        //3
        public  int usb_scump(int usbs[], int buget){
            int max=-1;
            for(int usb: usbs){
                if(usb<=buget && usb>max){
                    max=usb;
                }
            }
            return max;
        }

        //4
        public int suma_maxima_buget(int buget,int[] tastaturi, int[] usbs){
            int max=-1;
            for(int tastatura:tastaturi){
                for(int usb:usbs){
                    int total=tastatura+usb;
                    if(total<=buget && total>max){
                        max=total;
                    }
                }
            }
            if(max==-1){
                return -1;
            }
            else{
                return max;
            }
        }
}
