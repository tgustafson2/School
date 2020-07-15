/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment_6_monthdays;

/**
 *
 * @author tgust
 * Instructions: Fill out your name under programmer name, the date and time you started the assignment, 
the date and time you completed the assignment, total hours you dedicated to the assignment (should be
a minimum of 1 1/2 hours for a good quality, well done assignment - rules of academic honesty apply for
this), and any constructive comments you have about the assignment (could be things you liked about the 
assignment; or if you had the opportunity to do the assignment all over again, what would you do 
differently?) 

Programmer Name:Thomas Gustafson
Assignment Start:5/5/19
Assignment Completion:5/6/19
Total Hours for Assignment:2.5
Comments:The error testing in the book wasn't clear enough so I came in for clarification
 */
import java.util.Scanner;
public class Gustafson_Assignment_6_monthdays {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       try{
            int month, year;
        System.out.println("Enter the month (1=January, 2=February, ..., 12=December):");
        Scanner input = new Scanner (System.in);
        month= input.nextInt();
        System.out.println ("Enter the year:");
        year= input.nextInt();
        MonthDays mdata= new MonthDays(year, month);
        System.out.println();
        System.out.printf("%d/%d has %d days", mdata.getMonth(), mdata.getYear(), mdata.getNumberOfDays());
       }
       catch (Exception e){
           System.out.println(e.getMessage());
       } 
        
    }
    
}
