package Kiste;

public class Scheren implements Sache{
    private double weight;

    public Scheren(double weight){
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
        return "Scheren{"+"weight="+weight+"}";
    }
}
