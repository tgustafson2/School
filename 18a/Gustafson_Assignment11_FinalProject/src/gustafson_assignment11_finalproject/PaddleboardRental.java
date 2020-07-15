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
public class PaddleboardRental extends SummerSportRental {
    private int size;
    private Paddle style;
    public PaddleboardRental(int size, Paddle style, boolean newModel, double rentalCost, long rentalNumber){
    super(newModel, rentalCost, rentalNumber);
    setSize(size);
    setStyle(style);
    }
    public void setSize(int size){
        while (size<0){
            System.out.println("Invalid Size. Reenter Size:");
            Scanner input= new Scanner (System.in);
            size=input.nextInt();
        }
        this.size=size;
    }
    public void setStyle(Paddle style){
        this.style=style;
    }
    public int getSize(){
        return size;
    }
    public Paddle getStyle(){
        return style;
    }
    @Override
    public double lateCharge(){
        return .2*getrentalCost();
    }
    @Override
    public String toString(){
        return String.format("Size:%d cm\nStyle:%s\nCost:%.2f\nRental Number:%d\nNew Model:%b",
                size, style, getrentalCost(),getrentalNumber(), getnewModel());
    }
    
}
