package movie;

import java.util.List;
public class ComedyMovie extends Movie {
    public ComedyMovie(String title, int year, double rating, List<String> cast, double basePrice){
        super(title, year, rating, cast, basePrice);
    }

    @Override
    public double calculatePrice(){
        if(cast.contains("Adams Sandle")){
            return basePrice*0.5;
        }else{
            return basePrice;
        }
    }

}
