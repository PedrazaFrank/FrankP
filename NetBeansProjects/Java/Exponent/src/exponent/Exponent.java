package exponent;

import java.util.Scanner;

public class Exponent {

    public static int exponent(){
        Scanner keyboard = new Scanner(System.in);
        int ex = 1;
        
        System.out.println("Enter two numbers to find the exponent of the two numbers.");
        
        System.out.printf("Enter the base number: ");
        int base = keyboard.nextInt();
        
        System.out.printf("Enter the exponent: ");
        int exp = keyboard.nextInt();
        
        for(int i=1; i<=exp; i++){
            ex *= base;
            
        }
        
        return ex;
    }
    
    public static int gcd(){
        Scanner keyboard = new Scanner(System.in);
        
        System.out.println("Enter two numbers to find the greatest common divisor.");
        
        System.out.printf("Enter a number for X: ");
        int x = keyboard.nextInt();

        System.out.printf("Enter a number for Y: ");
        int y = keyboard.nextInt();
        
        int gcd = 0;
        int X = x;
        int Y = y;
        
        if(x!= 0 && y!=0){
            if(x>y){
            for(int i=x; x>y; i++){
                x = x-y;
                X=x;
            }
        }
        
            if(y>x){
            for(int j=y; y>x; j++){
                y = y-x;
                Y=y;
            }
        }
            
        }
        
        if(x==y){
                gcd = x;
            } 
        
        return gcd;
    }
    
    public static void main(String[] args) {
        
        System.out.println(exponent());
        System.out.println(gcd());
        
        
        
    }
       
}
