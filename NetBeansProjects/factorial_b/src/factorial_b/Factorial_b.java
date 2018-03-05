package factorial_b;

import java.util.Scanner;

public class Factorial_b {

    public static void main(String[] args) {
        
        Scanner keyboard = new Scanner ( System.in );
        
        System.out.print("Enter a number to find the log of that number: ");
        double num;
        
        num = keyboard.nextInt();
        
        System.out.printf("log(%.2f) is %f",num, Math.log(num));
    }
    
}
