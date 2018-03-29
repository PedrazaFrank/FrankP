import java.*;

public abstract class Rental {
    
   private boolean newModel;
   double rentalCost;
   private long rentalNumber;

    public Rental(boolean newModel, double rentalCost, long rentalNumber) {
        this.newModel = newModel;
        this.rentalCost = rentalCost;
        this.rentalNumber = rentalNumber;
    }
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Rental other = (Rental) obj;
        if (this.rentalNumber != other.rentalNumber) {
            return false;
        }
        return true;
    }
    
    public boolean isNewModel() {
        return newModel;
    }

    public void setNewModel(boolean newModel) {
        this.newModel = true;
    }

    public double getRentalCost() {
        return rentalCost;
    }

    public void setRentalCost(double rentalCost) {
       if( this.rentalCost>0 ) this.rentalCost = rentalCost;
       else {
           throw new IllegalArgumentException("Rental number must be greater than $0.\n You entered: $"+this.rentalCost);
       }
    }

    public long getRentalNumber() {
        return rentalNumber;
    }

    public void setRentalNumber(long rentalNumber) {
       if( this.rentalNumber<100 || this.rentalNumber>10000 ) throw new IllegalArgumentException("Rental number must be between 100 and 10000. You entered: "+this.rentalNumber);
       else {
           this.rentalNumber = rentalNumber;
       }
    }
    
    public abstract double lateCharge();
}