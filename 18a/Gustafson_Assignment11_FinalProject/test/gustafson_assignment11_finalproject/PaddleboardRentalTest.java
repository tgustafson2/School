/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment11_finalproject;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author tgust
 */
public class PaddleboardRentalTest {
    
    public PaddleboardRentalTest() {
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
     * Test of setSize method, of class PaddleboardRental.
     */
    @Test
    public void testSetSize() {
        System.out.println("setSize");
        int size = 110;
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        instance.setSize(size);
        assertEquals(size,instance.getSize());
        // TODO review the generated test code and remove the default call to fail.
        //fail("setSize failed");
    }

    /**
     * Test of setStyle method, of class PaddleboardRental.
     */
    @Test
    public void testSetStyle() {
        System.out.println("setStyle");
        Paddle style = Paddle.Single;
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        instance.setStyle(style);
        assertEquals(style, instance.getStyle());
        // TODO review the generated test code and remove the default call to fail.
        //fail("setStyle failed");
    }

    /**
     * Test of getSize method, of class PaddleboardRental.
     */
    @Test
    public void testGetSize() {
        System.out.println("getSize");
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        int expResult = 100;
        int result = instance.getSize();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("getSize failed");
    }

    /**
     * Test of getStyle method, of class PaddleboardRental.
     */
    @Test
    public void testGetStyle() {
        System.out.println("getStyle");
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        Paddle expResult = Paddle.Double;
        Paddle result = instance.getStyle();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("getStyle failed");
    }

    /**
     * Test of lateCharge method, of class PaddleboardRental.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        double expResult = .2*29.99;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        //fail("lateCharge failed");
    }

    /**
     * Test of toString method, of class PaddleboardRental.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        PaddleboardRental instance = new PaddleboardRental(100, Paddle.Double, true, 29.99, 5494);
        String expResult = "Size:100 cm\nStyle:Double\nCost:29.99\nRental Number:5494\nNew Model:true";
        String result = instance.toString();
        
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("toString failed");
    }
    
}
