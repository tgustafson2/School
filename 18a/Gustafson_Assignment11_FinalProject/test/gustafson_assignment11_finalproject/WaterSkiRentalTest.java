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
public class WaterSkiRentalTest  {
    
    
    public WaterSkiRentalTest() {
        
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
     * Test of setSize method, of class WaterSkiRental.
     */
    @Test
    public void testSetSize() {
        System.out.println("setSize");
        int size =70;
        WaterSkiRental instance = new WaterSkiRental(60, true, 29.99, 5494);
        instance.setSize(size);
        assertEquals(size, instance.getSize());
        // TODO review the generated test code and remove the default call to fail.
        //fail("setSize failed");
    }

    /**
     * Test of getSize method, of class WaterSkiRental.
     */
    @Test
    public void testGetSize() {
        System.out.println("getSize");
        WaterSkiRental instance =new WaterSkiRental(60, true, 29.99, 5494);
        int expResult = 60;
        int result = instance.getSize();
        
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("getSize failed");
    }

    /**
     * Test of lateCharge method, of class WaterSkiRental.
     */
    @Test
    public void testLateCharge() {
        System.out.println("lateCharge");
        WaterSkiRental instance = new WaterSkiRental(60, true, 29.99, 5494);
        double expResult = .1*29.99;
        double result = instance.lateCharge();
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        //fail("lateCharge failed");
    }

    /**
     * Test of toString method, of class WaterSkiRental.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        WaterSkiRental instance = new WaterSkiRental(60, true, 29.99, 5494);
        String expResult = "Size:60 cm\nCost:29.99\nRental Number:5494\nNew Model:true";
        String result = instance.toString();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("toString failed");
    }
    @Test
    public void testSetnewModel(){
        System.out.println("setnewModel");
        WaterSkiRental instance= new WaterSkiRental(60, true, 29.99, 5494);
        boolean rental=false;
        instance.setnewModel(rental);
        assertEquals(rental,instance.getnewModel());
       
        
        //fail("setnewRental failed");
        
    }
    @Test
    public void testGetnewModel(){
        System.out.println("getnewModel");
        WaterSkiRental instance= new WaterSkiRental(60, true, 29.99, 5494);
        boolean expResult= true;
        boolean result=instance.getnewModel();
        assertEquals(expResult, result);
        //fail("getnewModel failed");
    }
    @Test
    public void testSetrentalCost(){
        System.out.println("setrentalCost");
        WaterSkiRental instance= new WaterSkiRental(60,true, 29.99, 5494);
        double cost=34.99;
        instance.setrentalCost(cost);
        assertEquals(cost,instance.getrentalCost(),0.0);
        //fail("setrentalCost failed");
    }
    @Test
    public void testGetrentalCost(){
        System.out.println("getrentalCost");
        WaterSkiRental instance= new WaterSkiRental(60, true, 29.99, 5494);
        double expResult=29.99;
        double result=instance.getrentalCost();
        assertEquals(expResult, result,0.0);
        //fail("getrentalCost failed");
    }
    @Test
    public void testSetrentalNumber(){
        System.out.println("setrentalNumber");
        WaterSkiRental instance= new WaterSkiRental(60,true, 29.99, 5494);
        long rentnum=1319;
        instance.setrentalNumber(rentnum);
        assertEquals(rentnum,instance.getrentalNumber());
        //fail("setrentalNumber failed");
    }
    @Test
    
    public void testGetrentalNumber(){
        System.out.println("getrentalNumber");
        WaterSkiRental instance= new WaterSkiRental(60, true, 29.99, 5494);
        long expResult=5494;
        long result=instance.getrentalNumber();
        assertEquals(expResult, result);
        //fail("getrentalNumber failed");
    }
    @Test
    public void testEquals(){
        System.out.println("equals");
        WaterSkiRental instance1 = new WaterSkiRental(60, true, 29.99, 5494);
        WaterSkiRental instance2 = new WaterSkiRental(60, true, 29.99, 5494);
        boolean expResult=true;
        boolean result=instance1.equals(instance2.getrentalNumber());
        assertEquals(expResult, result);
        //fail("equals failed");
        
    }
    
}
