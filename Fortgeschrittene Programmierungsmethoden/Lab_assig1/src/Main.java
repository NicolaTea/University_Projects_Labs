import java.util.Scanner;
public class Main {

    public static int[] citire_input(int size){
        Scanner scanner=new Scanner(System.in);
        int[] array=new int[size];
        System.out.println("Introduceti "+size+" elemente: ");
        for(int i=0;i<size;i++){
            array[i]=scanner.nextInt();
        }
        return array;
    }
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        while(true){
            System.out.println("~Aufgaben~");
            System.out.println("1. Aufgabe1");
            System.out.println("2. Aufgabe2");
            System.out.println("3. Aufgabe3");
            System.out.println("4. Aufgabe4");
            System.out.println("5. Exit");
            System.out.print("Alegeti un exercitiu: ");
            int choice=scanner.nextInt();
            if(choice==5){
                System.out.println("Exiting...");
                break;
            }
            switch (choice){
                case 1:
                    System.out.print("Introduceti numarul de note: ");
                    int n=scanner.nextInt();
                    int[] note=Main.citire_input(n);
                    Aufgabe1 sistem_notare=new Aufgabe1();

                    //1
                    int[] noteInsuficiente=sistem_notare.NoteInsuficiente(note);
                    System.out.print("Note insuficiente: ");
                    for (int nota : noteInsuficiente) {
                        System.out.print(nota + " ");
                    }
                    System.out.println();

                    //2
                    double medie=sistem_notare.ValoareMedie(note);
                    System.out.println("Media: "+ medie);

                    //3
                    int[] rotunjite = sistem_notare.NoteRotunjite(note);
                    System.out.print("Note rotunjite: ");
                    for (int nota : rotunjite) {
                        System.out.print(nota + " ");
                    }
                    System.out.println();

                    //4
                    int maxRotunjit = sistem_notare.NotaMaximaRotunjita(note);
                    System.out.println("Nota maxima rotunjita: " + maxRotunjit);
                    break;
                case 2:
                    System.out.print("Introduceti numarul de elemente: ");
                    int m=scanner.nextInt();
                    int[] elem=citire_input(m);
                    Aufgabe2 operations=new Aufgabe2();

                    //1
                    System.out.println("Valoarea maxima: "+operations.maxim(elem));
                    //2
                    System.out.println("Valoarea minima: "+operations.minim(elem));
                    //3
                    System.out.println("Suma maxima: "+operations.suma_maxima(elem));
                    //4
                    System.out.println("Suma minima: "+operations.suma_minima(elem));
                    break;
                case 3:
                    System.out.print("Introduceti numarul de elemente: ");
                    int length=scanner.nextInt();
                    int[] num1=citire_input(length);
                    int[] num2=citire_input(length);
                    System.out.print("Introdu o cifra pt mul: ");
                    int digit1=scanner.nextInt();
                    System.out.print("Introdu o cifra pt div: ");
                    int digit2=scanner.nextInt();
                    Aufgabe3 op=new Aufgabe3();

                    //1
                    int[] sum_result=op.suma(num1,num2);
                    System.out.print("Suma: ");
                    for(int nr:sum_result){
                        System.out.print(nr);
                    }
                    System.out.println();

                    //2
                    int[] sub_result=op.diferenta(num1,num2);
                    System.out.print("Diff: ");
                    for(int nr: sub_result){
                        System.out.print(nr);
                    }
                    System.out.println();

                    //3
                    int[] mul_result= op.mul(num1,digit1);
                    System.out.print("Mul: ");
                    for(int nr:mul_result){
                        System.out.print(nr);
                    }
                    System.out.println();

                    //4
                    int[] div_result= op.div(num2,digit2);
                    System.out.print("Div: ");
                    for(int nr:div_result){
                        System.out.print(nr);
                    }
                    System.out.println();
                    break;
                case 4:
                    System.out.print("Introduceti numarul de tastaturi: ");
                    int t = scanner.nextInt();
                    int[] tastaturi=citire_input(t);
                    System.out.print("Introduceti numarul de usb-uri: ");
                    int u = scanner.nextInt();
                    int[] usbs=citire_input(u);
                    System.out.print("Introduceti un buget: ");
                    int buget=scanner.nextInt();
                    Aufgabe4 op_gadget=new Aufgabe4();

                    //1
                    System.out.println("Tastatura ieftina: "+op_gadget.tastatura_ieftina(tastaturi));
                    //2
                    System.out.println("Electro scump: "+op_gadget.gagdet_scump(tastaturi,usbs));
                    //3
                    System.out.println("Usb scump incadrat in buget: "+op_gadget.usb_scump(usbs,buget));
                    //4
                    System.out.println("Suma maxima de bani cheltuiti incadrati in buget: "+op_gadget.suma_maxima_buget(buget,tastaturi,usbs));
                    break;
                default:
                    System.out.println("Invalid choice");

            }
        }
        scanner.close();


    }
}