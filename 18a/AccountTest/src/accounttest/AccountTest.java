/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package accounttest;

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
Assignment Completion:5/5/19
Total Hours for Assignment:1.75
Comments:Pretty simple, some outside research for what bigdecimal functions are
 */

// Fig. 7.9: AccountTest.java
// Inputting and outputting floating-point numbers with Account objects.
import java.util.Scanner;
import java.math.BigDecimal;
import java.text.NumberFormat;

public class AccountTest
{
   public static void main(String[] args) 
   {
      Account account1 = new Account("Jane Green", 50.00);
      Account account2 = new Account("John Blue", -7.53); 

      // display initial balance of each object
      System.out.printf("%s balance: $%.2f%n",
         account1.getName(), account1.getBalance()); 
      System.out.printf("%s balance: $%.2f%n%n",
         account2.getName(), account2.getBalance()); 

      // create a Scanner to obtain input from the command window
      Scanner input = new Scanner(System.in);

      System.out.print("Enter deposit amount for account1: "); // prompt
      double depositAmounti = input.nextDouble(); // obtain user input
      BigDecimal depositAmount= BigDecimal.valueOf(depositAmounti);
      System.out.printf("%nadding %.2f to account1 balance%n%n", 
         depositAmount);
      account1.deposit(depositAmount); // add to account1's balance

      // display balances
      System.out.printf("%s balance: $%.2f%n",
         account1.getName(), account1.getBalance()); 
      System.out.printf("%s balance: $%.2f%n%n",
         account2.getName(), account2.getBalance()); 

      System.out.print("Enter deposit amount for account2: "); // prompt
      depositAmounti = input.nextDouble(); // obtain user input
      depositAmount= BigDecimal.valueOf(depositAmounti);
      System.out.printf("%nadding %.2f to account2 balance%n%n", 
         depositAmount);
      account2.deposit(depositAmount); // add to account2 balance

      // display balances
      System.out.printf("%s balance: %20s%n", 
         account1.getName(), NumberFormat.getCurrencyInstance().format(account1.getBalance())); 
      System.out.printf("%s balance: %20s%n%n",
         account2.getName(), NumberFormat.getCurrencyInstance().format(account2.getBalance())); 
   } // end main
} // end class AccountTest

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
