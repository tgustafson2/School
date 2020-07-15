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
public class Gustafson_Assignment9_Abstract {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Hamburger item1= new Hamburger();
        Steak item2= new Steak();
        Salad item3= new Salad();
        Salad item4= new Salad();
        
        Menu[]order=new Menu[4];
        order[0]=item1;
        order[1]=item2;
        order[2]=item3;
        order[3]=item4;
        
        for (Menu currentOrder: order){
            System.out.println(currentOrder);
        }
        System.out.printf("Total:$%.2f", order[0].getfcost());
        
    }
    
}
