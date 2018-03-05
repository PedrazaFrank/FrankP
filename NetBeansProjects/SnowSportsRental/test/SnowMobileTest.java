
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

public class SnowMobileTest {
    
    public SnowMobileTest() {
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
     * Test of lateCharge method, of class SnowMobile.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        SnowMobile instance = new SnowMobile(true, 42, 554);
        double expResult = 42;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
    }

    /**
     * Test of toString method, of class SnowMobile.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        SnowMobile instance = new SnowMobile(true, 49, 548);
        String expResult = "SnowMobile{capacity=4, vin=1FAFP45X82F218129}";
        String result = instance.toString();
        assertEquals(expResult, result);
    }

    /**
     * Test of getCapacity method, of class SnowMobile.
     */
    @Test
    public void testGetCapacity() {
        System.out.println("getCapacity");
        SnowMobile instance = new SnowMobile(true, 43, 532);
        int expResult = 4;
        int result = instance.getCapacity();
        assertEquals(expResult, result);
    }

    /**
     * Test of setCapacity method, of class SnowMobile.
     */
    @Test
    public void testSetCapacity() {
        System.out.println("setCapacity");
        int capacity = 4;
        SnowMobile instance = new SnowMobile(true, 44, 529);
        instance.setCapacity(capacity);
    }

    /**
     * Test of getVin method, of class SnowMobile.
     */
    @Test
    public void testGetVin() {
        System.out.println("getVin");
        SnowMobile instance = new SnowMobile(true, 46, 581);
        String expResult = "1FAFP45X82F218129";
        String result = instance.getVin();
        assertEquals(expResult, result);
    }

    /**
     * Test of setVin method, of class SnowMobile.
     */
    @Test
    public void testSetVin() {
        System.out.println("setVin");
        String vin = "1346258";
        SnowMobile instance = new SnowMobile(true, 44, 529);
        instance.setVin(vin);
    }
    
}
