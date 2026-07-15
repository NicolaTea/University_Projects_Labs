package Kiste;

public class Naegel implements Sache{
    @Override
    public double getWeight(){
        return 0.01;
    }

    @Override
    public boolean canCut(){
        return false;
    }

    @Override
    public String toString(){
        return "Naegel{}";
    }
}
