/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment3_salary;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Gustafson_Assignment3_Salary {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int days;
        double salary;
        Scanner input= new Scanner(System.in);
        System.out.printf("For how many days will the salary double?");
        days= input.nextInt();
        if ((days<1)||(days>45)){
            System.out.printf("Please enter a number between 1 and 45:");
            days= input.nextInt();
                    
        }
        String day="Day";
        String sal="Salary";
        System.out.printf("%-11s%s\n",day,sal);
        for (int i=0; i<days; i++){
            salary= Math.pow(2,i)/100;
            System.out.printf("%-10d $%10.2f\n", (i+1),salary);
        }
        
        
    }
    
}
