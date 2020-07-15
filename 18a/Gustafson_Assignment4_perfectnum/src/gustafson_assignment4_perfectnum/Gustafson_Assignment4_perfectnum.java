/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment4_perfectnum;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Gustafson_Assignment4_perfectnum {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int max;
        Scanner input= new Scanner (System.in);
        System.out.println("Enter the largest number to try to display(between 2 and 100000):");
        max= input.nextInt();
        if (max>100000){
            System.out.println("Invalid entry please reenter:");
            max= input.nextInt();
        }
        for (int number=2; number<=max; number++){
            String perfectnum;
            perfectnum = isPerfect(number);
            if (perfectnum!=null){
                System.out.printf("%d is perfect", number);
                System.out.printf("\n\tFactors: %s\n", perfectnum);
            }
        }
    }
    public static String isPerfect(int number){
        String factors="";
        
        int factorsum=0;
        for (int i=1; i<number; i++){
            if ((number%i)==0){
                factorsum+=i;
                factors+=i+" ";
                
            }
        }
        if (factorsum!=number){
            factors= null;
        }
        
        return factors;
    }
    
}

