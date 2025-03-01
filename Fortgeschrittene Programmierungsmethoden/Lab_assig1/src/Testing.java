import java.util.Arrays;

public class Testing {
    public static void main(String args[]){
            //auf1
            int[] note = {29, 37, 38, 41, 84, 67};

            // 1. Note insuficiente
            Aufgabe1 sistemNotare= new Aufgabe1();
            int[] insuficiente = sistemNotare.NoteInsuficiente(sistemNotare.NoteRotunjite(note));
            System.out.print("Note insuficiente: ");
            for (int nota : insuficiente) {
                    System.out.print(nota + " ");
            }
            System.out.println();

            // 2. Valoare medie..ceva nu iasa
            double medie = sistemNotare.ValoareMedie(note);
            System.out.println("Valoarea medie: " + medie);

            // 3. Note rotunjite
            int[] rotunjite = sistemNotare.NoteRotunjite(note);
            System.out.print("Note rotunjite: ");
            for (int nota : rotunjite) {
                    System.out.print(nota + " ");
            }
            System.out.println();

            // 4. Nota maxima rotunjita
            int maxRotunjit = sistemNotare.NotaMaximaRotunjita(note);
            System.out.println("Nota maxima rotunjita: " + maxRotunjit);

            System.out.println("-----------------------------------------------");

            //auf2
            Aufgabe2 op_array=new Aufgabe2();
            int number[]={4,8,3,10,17};
            //1
            int max=op_array.maxim(number);
            System.out.println("Valoarea maxima: "+max);
            //2
            int min=op_array.minim(number);
            System.out.println("Valoarea minima: "+min);
            //3
            int max_sum=op_array.suma_maxima(number);
            System.out.println("Suma maxima: "+max_sum);
            //4
            int min_sum=op_array.suma_minima(number);
            System.out.println("Suma minima: "+min_sum);

            System.out.println("-----------------------------------------------");

            //auf3
            Aufgabe3 op=new Aufgabe3();
            //1
            int[] num1={1,3,0};
            int[]num2={8,7,0};
            int[] sum_result=op.suma(num1,num2);
            System.out.println("Suma: "+Arrays.toString(sum_result));

            //2
            int[] sub_result=op.diferenta(num1,num2);
            System.out.println("Diff: "+Arrays.toString(sub_result));

            //3
            int[] num3={2,3,6,0,0,0,0,0,0};
            int[] mul_result= op.mul(num3,1);
            System.out.println("Mul: "+Arrays.toString(mul_result));

            //4
            int[] div_result= op.div(num3,-2);
            System.out.println("Div: "+Arrays.toString(div_result));
            System.out.println("-----------------------------------------------");

            //auf4
            Aufgabe4 op_gadget=new Aufgabe4();
            //1
            int[] tastaturi={40,35,70,15,45};
            System.out.println("Tastatura ieftina: "+op_gadget.tastatura_ieftina(tastaturi));
            //2
            int[] tast2={15,20,10,35};
            int[] usbs2={20,15,40,15};
            System.out.println("Electro scump: "+op_gadget.gagdet_scump(tast2,usbs2));
            //3
            int[] usbs3={15,45,20};
            int buget=30;
            System.out.println("Usb scump incadrat in buget: "+op_gadget.usb_scump(usbs3,buget));
            //4
            int b=60;
            int[] tast4={60};
            int [] usbs4={8,12};
            System.out.println("Suma maxima de bani cheltuiti incadrati in buget: "+op_gadget.suma_maxima_buget(b,tast4,usbs4));

    }
}
