package calculating_pi;

import java.util.Scanner;

public class Calculating_pi {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number to calculate pi to that term: ");
        
        double term = input.nextInt();
        double sum = 0;
        
        for( int x=0; x<term; x++){
            sum += Math.pow(-1,x)/(2*x+1);
        }
        
        sum = sum*4;
        System.out.printf("The value of pi up to your number is %.5f.\n", sum);
        
    }
    
}
