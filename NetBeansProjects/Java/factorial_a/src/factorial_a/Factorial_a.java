package factorial_a;

import java.util.Scanner;

public class Factorial_a {

    public static void main(String[] args) {
        
        Scanner keyboard = new Scanner ( System.in );
        
        System.out.print("Enter a number to find the factorial of that number: ");
        int num;
        long fact = 1;
        
        num = keyboard.nextInt();
        
        for (int x=num; x>=1; x--) {
            fact = fact * x;
        }
        
        System.out.println("The factorial of " + num + " is " + fact );
    }
    
}
