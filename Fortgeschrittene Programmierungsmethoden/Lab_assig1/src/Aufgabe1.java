public class Aufgabe1 {
    //1
    public int[] NoteInsuficiente(int[] note){
        //numaram notele<40
        int counter=0;
        for(int nota:note){
            if(nota<40){
                counter++;
            }
        }
        //creeam un array cu notele insuficiente
        int[] n_insuficiente=new int[counter];
        int idx=0;
        for(int nota:note){
            if(nota<40){
                n_insuficiente[idx++]=nota;
            }
        }
        return n_insuficiente;
    }

    //2
    public double ValoareMedie(int[] note){
        int sum=0;
        for(int nota:note){
            sum+=nota;
        }
        return Math.round((double)sum/note.length*100.0)/100.0;
    }

    //3
    public int[] NoteRotunjite(int[] note){
        int[] n_rotunjite=new int[note.length];
        for(int i=0;i<note.length;i++){
            n_rotunjite[i]=Rotunjire(note[i]);
        }
        return n_rotunjite;

    }

    public  int Rotunjire(int nota){ //metoda aux
        if(nota<38){
            return nota;
        }
        int diff=5-(nota%5);
        if(diff<3){
            return nota+diff;  //rotunjim la urm. multiplu de 5
        }
        return nota;
    }

    //4
    public  int NotaMaximaRotunjita(int [] note){
        int max=0;
        int[] n_rotunjite=NoteRotunjite(note);
        for(int nota: n_rotunjite){
            if(nota>max){
                max=nota;
            }
        }
        return max;
    }

}
