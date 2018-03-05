package multiples;

import java.util.Scanner;

public class Multiples {

    public static void main(String[] args) {
        
        Scanner input = new Scanner ( System.in );
        
        int num1, num2;
        
        System.out.println("Enter two numbers to determine if the second number is a multiple of the first.");
        
        System.out.print("Number 1: ");
        num1 = input.nextInt();
        System.out.print("Number 2: ");
        num2 = input.nextInt();
        
        if(num1%num2==0)
        {
            System.out.println("Your second number is a multiple of the first number.");
        }
        
        if(num1%num2!=0)
        {
            System.out.println("Your second number is not a multiple of the first number.");
        }
    }
    
}
