/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment9_abstract;

/**
 *
 * @author tgust
 */
public abstract class Menu {
    private double price;
    private static double fcost=0;
    
    public Menu(double price){
        this.price=price;
        fcost+=price;
        
    }
    public void addPrice(double price){
        this.price+=price;
        fcost+=price;
    }
    public double getPrice(){
        return price;
    }
    public double getfcost(){
        return fcost;
    }
    @Override
    public abstract String toString();
   
}
