import java.*;

public class Ski extends Rental {
    
    private int size;

    public Ski(boolean newModel, double rentalCost, long rentalNumber) {
        super(newModel, rentalCost, rentalNumber);
        size = 165;
    }
    
    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    @Override
    public double lateCharge(){
        double lateCost=0.10; 
        double lateCharge = (rentalCost*lateCost)+rentalCost;
        return lateCharge;
    }

    @Override
    public String toString() {
        return "Ski{" + "size=" + size + '}';
    }

}