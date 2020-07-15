/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment2_int;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Gustafson_Assignment2_Int {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int num1, num2, num3, num4, min, max;
        Scanner input = new Scanner(System.in);
        System.out.printf("Enter the first nummber:");
        num1 = input.nextInt();
        System.out.printf("Enter the second nummber:");
        num2 = input.nextInt();
        System.out.printf("Enter the third nummber:");
        num3 = input.nextInt();
        System.out.printf("Enter the fourth nummber:");
        num4 = input.nextInt();
        min = num1;
        max= num1;
        if (min>num2){
            min=num2;
        }
        if (min>num3){
            min=num3;
        }
        if (min>num4){
            min=num4;
        }
        if (max<num2){
            max=num2;
        }
        if (max<num3){
            max=num3;
        }
        if (max<num4){
            max=num4;
        }
        System.out.printf("The values enter: %d, %d, %d, %d " ,num1, num2, num3, num4);
        System.out.printf("have a minimum value %d and a maximum value %d", min, max);
    }
    
}
