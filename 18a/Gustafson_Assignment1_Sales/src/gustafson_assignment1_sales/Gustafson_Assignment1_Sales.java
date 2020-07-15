/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment1_sales;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Gustafson_Assignment1_Sales {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int year;
        double sales, countytax, statetax, totaltax, totalrevenue;
        String month;
        Scanner scan = new Scanner (System.in);
        Scanner input = new Scanner (System.in);
        System.out.println("What month is it?");
        month= scan.next();
        System.out.println("What year is it?");
        year = input.nextInt();
        System.out.println("What was the total amount collected?");
        sales= input.nextFloat();
        totalrevenue= sales/1.0875;
        countytax=totalrevenue*.02;
        statetax=totalrevenue*.0875;
        totaltax= countytax+ statetax;
        System.out.printf("Month: %s %d%n", month, year);
        System.out.printf("Total Collected:$ %,10.2f%n", sales);
        System.out.printf("Sales:$ %,20.2f%n", totalrevenue);
        System.out.printf("County Sales Tax:$ %,9.2f%n", countytax);
        System.out.printf("State Sales Tax:$ %,10.2f%n", statetax);
        System.out.printf("Total Sales Tax:$ %,10.2f%n", totaltax);
        
        
        
        
        
        
    }
    
}
