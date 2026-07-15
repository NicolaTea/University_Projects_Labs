package karte;

public class Karte {
    private final String farbe;
    private final int wert;

    public Karte(String farbe,int wert){
        this.farbe=farbe;
        this.wert=wert;
    }

    @Override
    public String toString() {
        return "Karte{" + "farbe='" + farbe + '\'' + ", wert=" + wert + '}';
    }
}
