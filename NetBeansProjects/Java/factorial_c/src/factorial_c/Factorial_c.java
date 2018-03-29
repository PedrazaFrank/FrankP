package factorial_c;

import java.util.Scanner;

public class Factorial_c {

    public static void main(String[] args) {
        
        Scanner keyboard = new Scanner ( System.in );
        
        System.out.print("Enter a number to find the exponential factor of that number: ");
        double num;
        
        num = keyboard.nextInt();
        
        System.out.printf("e^(%.2f) is %.3f",num, Math.exp(num));
    }
    
}
