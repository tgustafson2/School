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
public abstract class SummerSportRental {
    private boolean newModel;
    private double rentalCost;
    private long rentalNumber;
    
    public SummerSportRental(boolean newModel, double rentalCost, long rentalNumber){
        
        setnewModel(newModel);
        setrentalCost(rentalCost);
        setrentalNumber(rentalNumber);
    }
    public void setnewModel(boolean newModel){
        this.newModel=newModel;
    }
    public void setrentalCost(double rentalCost){
        while (rentalCost<0){
            System.out.println("Rental Cost must be positive. Please Reenter Cost:");
            Scanner input= new Scanner (System.in);
            rentalCost= input.nextDouble();
        }
        this.rentalCost=rentalCost;
    }
    public void setrentalNumber(long rentalNumber){
        while (rentalNumber<0){
            System.out.println("Rental Number must be positive. Please Reenter Number:");
            Scanner input= new Scanner (System.in);
            rentalNumber= input.nextLong();
        }
        this.rentalNumber=rentalNumber;
    }
    public boolean getnewModel(){
        return newModel;
    }
    public double getrentalCost(){
        return rentalCost;
    }
    public long getrentalNumber(){
        return rentalNumber;
    }
    public boolean equals(long num1){
        if (num1==rentalNumber){
            return true;
        }
        else
            return false;
    }
    public abstract double lateCharge();
    
        
    
    
}
