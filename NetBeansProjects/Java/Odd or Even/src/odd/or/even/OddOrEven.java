package odd.or.even;

import java.util.Scanner;

public class OddOrEven {

    public static void main(String[] args) {
        
        Scanner input = new Scanner ( System.in );
        
        int number;
        
        System.out.print("Enter a number to determine if it is even or odd: ");
        number = input.nextInt();
        
        if(number%2==0)
        {
            System.out.println("Your number is even.");
        }
        
        if(number%2!=0)
        {
            System.out.println("Your number is odd.");
        }
    }
    
}
