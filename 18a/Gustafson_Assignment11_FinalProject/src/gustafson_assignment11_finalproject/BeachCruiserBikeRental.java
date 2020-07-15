/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment11_finalproject;

/**
 *
 * @author tgust
 */
import java.util.EnumSet;
import java.util.Scanner;
public class BeachCruiserBikeRental extends SummerSportRental {
    private int wheel_size;
    private CAPACITY capacity;
    public BeachCruiserBikeRental (int wheel_size, CAPACITY capacity, boolean newModel, double rentalCost, long rentalNumber){
        super(newModel, rentalCost, rentalNumber);
        setwheel_size(wheel_size);
        setcapacity(capacity);
    }
    
    public void setwheel_size(int wheel_size){
        while (wheel_size<0){
            System.out.println("Invalid Size. Reenter Size:");
            Scanner input= new Scanner (System.in);
            wheel_size=input.nextInt();
        }
        this.wheel_size=wheel_size;
    }
    
    public void setcapacity(CAPACITY capacity){
        this.capacity=capacity;
    }
    public int getwheel_size(){
        return wheel_size;
    }
    public CAPACITY getcapacity(){
        return capacity;
    }
    @Override
    public double lateCharge(){
        double carry;
        if (capacity==CAPACITY.Single){
            carry=1;
        }
        else if(capacity==CAPACITY.Double){
            carry=2;
        }
        else {
            carry=3;
        }
        return (20+5*carry)*getrentalCost()/100;
    }
    @Override
    public String toString(){
        return String.format("Wheel Size:%d cm\nCapacity:%s\nCost:%.2f\nRental Number:%d\nNew Model:%b",
                wheel_size, capacity, getrentalCost(),getrentalNumber(), getnewModel());
    }
}
