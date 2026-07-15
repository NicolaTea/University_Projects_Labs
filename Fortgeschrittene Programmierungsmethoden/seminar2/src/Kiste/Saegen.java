package Kiste;

public class Saegen implements Sache{
    private double weight;

    public Saegen(double weight){
        this.weight=weight;
    }

    @Override
    public double getWeight(){
        return weight;
    }

    @Override
    public boolean canCut(){
        return true;
    }

    @Override
    public String toString(){
        return "Saegen{"+"weight="+weight+"}";
    }
}
