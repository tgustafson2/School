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
import java.util.Scanner;
public class Hamburger extends Menu {
    private String entree;
    private String side;
    private double cost;
    public Hamburger(){
        super (4.50);
        System.out.printf("For your side would you like:%n");
        System.out.printf("1.Fries%n");
        System.out.printf("2.Side Salad%n");
        Scanner input = new Scanner (System.in);
        int choice= input.nextInt();
        if (choice==1){
            cost=4.50+1.50;
            addPrice(cost-4.50);
            side="Fries";
        }
        else if (choice==2){
            cost=4.50+1.00;
            addPrice(cost-4.50);
            side="Side Salad";
        }
        else{
            side="";
            cost=4.50;
        }
        entree="Hamburger";
       
        
    }
    @Override
    public String toString(){
        return String.format("%s\t%s\t%.2f",entree, side, cost);
    }
    
}
