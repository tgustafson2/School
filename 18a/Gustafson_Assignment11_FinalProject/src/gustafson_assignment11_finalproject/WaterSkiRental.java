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
import java.util.Scanner;
public class WaterSkiRental extends SummerSportRental {
    private int size;
    public WaterSkiRental(int size, boolean newModel, double rentalCost, long rentalNumber){
        super(newModel, rentalCost, rentalNumber);
        setSize(size);
    }
    public void setSize(int size){
        while (size<0){
            System.out.println("Invalid Size. Reenter Size:");
            Scanner input= new Scanner (System.in);
            size=input.nextInt();
        }
        this.size=size;
    }
    public int getSize(){
        return size;
    }
    
    @Override
    public double lateCharge(){
        
        return .1*getrentalCost();
    }
    @Override
    public String toString(){
        
        return String.format("Size:%d cm\nCost:%.2f\nRental Number:%d\nNew Model:%b",
                size, getrentalCost(),getrentalNumber(), getnewModel());
    }
    
}
