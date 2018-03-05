public class Snowboard extends Rental {
    
    private int size;
    private boolean freestyle;

    public Snowboard(boolean newModel, double rentalCost, long rentalNumber) {
        super(newModel, rentalCost, rentalNumber);
        size=150;
        freestyle=true;
    }

    @Override
    public double lateCharge() {
        double lateCost=0.20; 
        double lateCharge = (rentalCost*lateCost)+rentalCost;
        return lateCharge;
    }

    @Override
    public String toString() {
        return "Snowboard{" + "size=" + getSize() + ", freestyle=" + isFreestyle() +'}';
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public boolean isFreestyle() {
        return freestyle;
    }

    public void setFreestyle(boolean freestyle) {
        this.freestyle = freestyle;
    }

    public double getLateCharge() {
        double lateCost=0.20; 
        double lateCharge = (rentalCost*lateCost)+rentalCost;
        return lateCharge;
    }
    
}