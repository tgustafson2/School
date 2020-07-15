/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment_7a;

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
Assignment Start:5/5/2019
Assignment Completion:5/6/2019
Total Hours for Assignment:2
Comments:Fairly straight forward, I struggled at first how to setup the package for the enum constants though
 */
import java.util.EnumSet;
public class Gustafson_Assignment_7a {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("All Traffic Signals:");
        for (TrafficSignal signs: TrafficSignal.values()){
            System.out.printf("%-10s duration %d seconds%n",signs, signs.getDuration());
        }
        
    }
    
}
