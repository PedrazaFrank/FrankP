package exponent.gcd;

import java.util.Scanner;

public class ExponentGcd {

    public static void main(String[] args) {
        
        Scanner keyboard = new Scanner(System.in);
        
        System.out.println("Which equation would you like to calculate?");
        System.out.println("1. The exponent of two numbers.");
        System.out.println("2. The GCD of two numbers.");
        System.out.printf("Please enter the number corresponding with your choice: ");
        
        int choice = keyboard.nextInt();
        
        while(choice!=1 || choice!=2){
            System.out.println("Please enter a valid number.");
            System.out.println("1. The exponent of two numbers.");
        System.out.println("2. The GCD of two numbers.");
        System.out.printf("Please enter the number corresponding with your choice: ");
        
        choice = keyboard.nextInt();
        if(choice==1 || choice==2){
            break;
        }
        }
        
        if(choice == 1){
        System.out.println("The exponent of your two numbers is "+exponent()+"\n");
        }
        
        if(choice == 2){
        System.out.println("The GCD of the two numbers is "+gcd());
        }
  
    }
    
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
    
}
