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
public class BeachCruiserBikeRentalTest {
    
    public BeachCruiserBikeRentalTest() {
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
     * Test of setwheel_size method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testSetwheel_size() {
        System.out.println("setwheel_size");
        int wheel_size = 32;
        
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        instance.setwheel_size(wheel_size);
        assertEquals(wheel_size,instance.getwheel_size());
        // TODO review the generated test code and remove the default call to fail.
        //fail("setwheel_size failed");
    }

    /**
     * Test of setcapacity method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testSetcapacity() {
        System.out.println("setcapacity");
        CAPACITY capacity = CAPACITY.Triple;
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        instance.setcapacity(capacity);
        assertEquals(capacity, instance.getcapacity());
        // TODO review the generated test code and remove the default call to fail.
        //fail("setcapacity failed");
    }

    /**
     * Test of getwheel_size method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testGetwheel_size() {
        System.out.println("getwheel_size");
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        int expResult = 30;
        int result = instance.getwheel_size();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("getwheel_size failed");
    }

    /**
     * Test of getcapacity method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testGetcapacity() {
        System.out.println("getcapacity");
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        CAPACITY expResult = CAPACITY.Double;
        CAPACITY result = instance.getcapacity();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("getcapacity failed");
    }

    /**
     * Test of lateCharge method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        double expResult = 29.99*.30;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        //fail("lateCharge failed");
    }

    /**
     * Test of toString method, of class BeachCruiserBikeRental.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        BeachCruiserBikeRental instance = new BeachCruiserBikeRental(30, CAPACITY.Double, true, 29.99, 5494);
        String expResult = "Wheel Size:30 cm\nCapacity:Double\nCost:29.99\nRental Number:5494\nNew Model:true";
        String result = instance.toString();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("toString failed");
    }
    
    
}
