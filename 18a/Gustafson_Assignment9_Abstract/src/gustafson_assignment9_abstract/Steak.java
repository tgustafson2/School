/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment9_abstract;

import java.util.Scanner;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Steak extends Menu {
    private String entree;
    private String side;
    private double cost;
    public Steak(){
        super (10.00);
        System.out.printf("For your side would you like:%n");
        System.out.printf("1.Fries%n");
        System.out.printf("2.Side Salad%n");
        Scanner input = new Scanner (System.in);
        int choice= input.nextInt();
        if (choice==1){
            cost=10.00+1.50;
            addPrice(cost-10.00);
            side="Fries";
        }
        else if (choice==2){
            cost=10.00+1.00;
            addPrice(cost-10.00);
            side="Side Salad";
        }
        else{
            side="";
            cost=10.00;
        }
        entree="Steak";
       
        
    }
    @Override
    public String toString(){
        return String.format("%s\t%s\t%.2f",entree, side, cost);
    }
}
