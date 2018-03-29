
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

public class SkiTest {
    
    public SkiTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }


    /**
     * Test of equals method, of class Rental.
     */
    @Test
    public void testEquals() {
        System.out.println("equals");
        Object obj = 349;
        Rental instance = new Ski(false, 26, 15);
        boolean expResult = false;
        boolean result = instance.equals(obj);
        assertEquals(expResult, result);
    }

    /**
     * Test of isNewModel method, of class Rental.
     */
    @Test
    public void testIsNewModel() {
        System.out.println("isNewModel");
        Rental instance = new Ski(true, 26, 15);
        boolean expResult = true;
        boolean result = instance.isNewModel();
        assertEquals(expResult, result);
    }

    /**
     * Test of setNewModel method, of class Rental.
     */
    @Test
    public void testSetNewModel() {
        System.out.println("setNewModel");
        boolean newModel = false;
        Rental instance = new Ski(false, 26, 15);
        instance.setNewModel(newModel);
    }

    /**
     * Test of getRentalCost method, of class Rental.
     */
    @Test
    public void testGetRentalCost() {
        System.out.println("getRentalCost");
        Rental instance = new Ski(false, 26, 15);
        double expResult = 26;
        double result = instance.getRentalCost();
        assertEquals(expResult, result, 0.0);
    }

    /**
     * Test of setRentalCost method, of class Rental.
     */
    @Test
    public void testSetRentalCost() {
        System.out.println("setRentalCost");
        double rentalCost = 29;
        Rental instance = new Ski(false, 29, 349);
        instance.setRentalCost(rentalCost);
    }

    /**
     * Test of getRentalNumber method, of class Rental.
     */
    @Test
    public void testGetRentalNumber() {
        System.out.println("getRentalNumber");
        Rental instance = new Ski(false, 28, 384);
        long expResult = 384;
        long result = instance.getRentalNumber();
        assertEquals(expResult, result);
    }

    /**
     * Test of setRentalNumber method, of class Rental.
     */
    @Test
    public void testSetRentalNumber() {
        System.out.println("setRentalNumber");
        long rentalNumber = 0L;
        Rental instance = new Ski(false, 26, 267);
        instance.setRentalNumber(rentalNumber);
    }
    
    /**
     * Test of getSize method, of class Ski.
     */
    @Test
    public void testGetSize() {
        System.out.println("getSize");
        Ski instance = new Ski(false, 26, 15);
        int expResult = 165;
        int result = instance.getSize();
        assertEquals(expResult, result);
    }

    /**
     * Test of setSize method, of class Ski.
     */
    @Test
    public void testSetSize() {
        System.out.println("setSize");
        int size = 0;
        Ski instance = new Ski(true, 20, 168);
        instance.setSize(size);
    }

   /**
     * Test of lateCharge method, of class Ski.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        Ski instance = new Ski(true, 25, 15);
        double expResult = 27.5;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
    }

    /**
     * Test of toString method, of class Ski.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Ski instance = new Ski(false, 20, 159);
        String expResult = "Ski{size=165}";
        String result = instance.toString();
        assertEquals(expResult, result);
    }
    
    
}