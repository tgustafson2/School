/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gustafson_assignment5_arraystats;

/**
 *
 * @author tgust
 */
import java.util.Scanner;
public class Gustafson_Assignment5_arraystats {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int size;
        Scanner input = new Scanner (System.in);
        System.out.println("How many numbers of the type double do you want to store in your array?");
        size=input.nextInt();
        double[] array= new double [size];
        for (int i=0; i<array.length; i++){
            System.out.printf("Enter a value #%d:",i+1);
            array[i]=input.nextDouble();
        }
        double max=array[0], min=array[0],mean=0, deviation, ssdeviation;
        for (int j=0; j<array.length; j++){
            mean+=array[j];
            if (max<array[j]){
                max=array[j];
            }
            if (min>array[j]){
                min=array[j];
            }
            
        }
        mean/=array.length;
        deviation=sdeviation(array, mean);
        ssdeviation=ssdeviation(array, mean);
        System.out.println("The statistics for your user entered array is:\n");
        System.out.printf("%31s:%12.3f%n", "Minimum", min);
        System.out.printf("%31s:%12.3f%n", "Maximum", max);
        System.out.printf("%31s:%12.3f%n", "Average", mean);
        System.out.printf("%31s:%12.3f%n", "Standard deviation (population)", deviation);
        System.out.printf("%31s:%12.3f%n", "Standard deviation (sample)", ssdeviation);
        
    }
    public static double sdeviation(double []array, double avg){
        double sumdev=0;
        double deviation;
        for (int i=0; i<array.length; i++){
            
            sumdev+= (Math.pow((array[i]-avg), 2));
        }
        deviation= Math.sqrt(sumdev/array.length);
        return deviation;
    }
    public static double ssdeviation(double []array, double avg){
        double sumdev=0;
        double deviation;
        for (int i=0; i<array.length; i++){
            
            sumdev+= (Math.pow((array[i]-avg), 2));
        }
        deviation= Math.sqrt(sumdev/(array.length-1));
        return deviation;
    }
    
}
