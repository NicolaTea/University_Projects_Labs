package Kiste;
import java.util.List;
import java.util.ArrayList;


public class Kiste {
    private List<Sache> sachen=new ArrayList<>();

    public void add(Sache sache){
        sachen.add(sache);
    }

    public List<Sache> heavyObject(){
        return sachen.stream().filter(sache -> sache.getWeight()>1).toList();
    }

    public List<Sache> canCut(){
        return sachen.stream().filter(Sache::canCut).toList();
    }

    @Override
    public String toString(){
        return "Kiste{"+"sachen="+sachen+"}";
    }
}
