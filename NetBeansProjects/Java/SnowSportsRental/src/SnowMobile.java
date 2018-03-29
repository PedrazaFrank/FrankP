public class SnowMobile extends Rental {
    
    private int capacity;
    private String vin;

    public SnowMobile(boolean newModel, double rentalCost, long rentalNumber) {
        super(newModel, rentalCost, rentalNumber);
        capacity = 4;
        vin = "1FAFP45X82F218129";
    }

    @Override
    public double lateCharge() {
        double lateCost=(20+getCapacity()*5)/100; 
        double lateCharge = (rentalCost*lateCost)+rentalCost;
        return lateCharge;
    }

    @Override
    public String toString() {
        return "SnowMobile{" + "capacity=" + getCapacity() + ", vin=" + getVin() + '}';
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public String getVin() {
        return vin;
    }

    public void setVin(String vin) {
        this.vin = vin;
    }
    
}