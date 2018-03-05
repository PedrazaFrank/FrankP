
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

public class SnowboardTest {
    
    public SnowboardTest() {
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
     * Test of lateCharge method, of class Snowboard.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        Snowboard instance = new Snowboard(true, 42, 334);
        double expResult = 50.4;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
    }

    /**
     * Test of toString method, of class Snowboard.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Snowboard instance = new Snowboard(true, 43, 328);
        String expResult = "Snowboard{size=150, freestyle=true}";
        String result = instance.toString();
        assertEquals(expResult, result);
    }

    /**
     * Test of getSize method, of class Snowboard.
     */
    @Test
    public void testGetSize() {
        System.out.println("getSize");
        Snowboard instance = new Snowboard(true, 48, 335);
        int expResult = 150;
        int result = instance.getSize();
        assertEquals(expResult, result);
    }

    /**
     * Test of setSize method, of class Snowboard.
     */
    @Test
    public void testSetSize() {
        System.out.println("setSize");
        int size = 0;
        Snowboard instance = new Snowboard(true, 45, 395);
        instance.setSize(size);
    }

    /**
     * Test of isFreestyle method, of class Snowboard.
     */
    @Test
    public void testIsFreestyle() {
        System.out.println("isFreestyle");
        Snowboard instance = new Snowboard(true, 49, 323);
        boolean expResult = true;
        boolean result = instance.isFreestyle();
        assertEquals(expResult, result);
    }

    /**
     * Test of setFreestyle method, of class Snowboard.
     */
    @Test
    public void testSetFreestyle() {
        System.out.println("setFreestyle");
        boolean freestyle = false;
        Snowboard instance = new Snowboard(true, 46, 389);
        instance.setFreestyle(freestyle);
    }

    /**
     * Test of getLateCharge method, of class Snowboard.
     */
    @Test
    public void testGetLateCharge() {
        System.out.println("getLateCharge");
        Snowboard instance = new Snowboard(true, 44, 364);
        double expResult = 52.8;
        double result = instance.getLateCharge();
        assertEquals(expResult, result, 0.0);
    }
    
}
