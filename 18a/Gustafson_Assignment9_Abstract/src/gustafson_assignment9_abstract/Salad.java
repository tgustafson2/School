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
public class Salad extends Menu {
    private String salatype;
    private double cost;
    public Salad(){
        super(0.0);
        System.out.printf("Which salad would you like:%n");
        System.out.printf("1.Caesar Salad%n");
        System.out.printf("2.Cobb Salad%n");
        System.out.printf("3.Kale Salad%n");
        Scanner input= new Scanner (System.in);
        int choice = input.nextInt();
        if (choice==1){
            salatype="Caesar Salad";
            cost=6.49;
            addPrice(cost);
        }
        else if (choice==2){
            salatype="Cobb Salad";
            cost=6.00;
            addPrice(cost);
        }
        else if (choice==3){
            salatype="Kale Salad";
            cost=6.99;
            addPrice(cost);
        }
    }
    @Override
    public String toString(){
        return String.format("%s\t%.2f", salatype, cost);
    }
}
