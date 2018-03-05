package recursive;

import java.util.Scanner;
import java.lang.StringBuilder;

public class Recursive {

    public static void main(String[] args) {
        
        System.out.println(menu());
  
    }
    
    public static String menu(){
        
        Scanner keyboard = new Scanner(System.in);
        
        System.out.println("Which equation would you like to calculate?");
        System.out.println("1. The exponent of two numbers.");
        System.out.println("2. The GCD of two numbers.");
        System.out.println("3. Quit");
        System.out.printf("Please enter the number corresponding with your choice: ");
        
        int choice = keyboard.nextInt();
        System.out.println("\n");
        
        String end = "";
        
        if(choice<1 || choice>3){
            choice = 4;
        }
        
        switch(choice){
            case 1: 
                
                System.out.println("Enter two numbers to find the exponent of the two numbers.");

                System.out.printf("Enter the base number: ");
                int base = keyboard.nextInt();

                System.out.printf("Enter the exponent: ");
                int exp = keyboard.nextInt();
                
                System.out.println("The exponent of your two numbers is "+exponent(base, exp)+"\n");
                
                System.out.println(cont());
                
                break;
            case 2:
                System.out.println("Enter two numbers to find the greatest common divisor.");
        
                System.out.printf("Enter a number for X: ");
                int x = keyboard.nextInt();

                System.out.printf("Enter a number for Y: ");
                int y = keyboard.nextInt();
                
                System.out.println("The GCD of the two numbers is "+gcd(x, y)+"\n");
                
                System.out.println(cont());
                
                break;
            case 3:
                break;
            case 4:
                System.out.println("Invalid option. Please try again.\n");
                System.out.println(menu());
                break;
        }
        return end;
    }
    
    public static int exponent(int base, int exp){
        
        if(exp<=0){
            return 1;
        }
        return base * exponent(base, --exp);        
    }
    
    public static int gcd(int x, int y){
        
        if(y==0){
            return x;
        }
        else return gcd(y,x%y);

    }  
    
    public static String cont(){
        
        Scanner keyboard = new Scanner(System.in);
        
        System.out.printf("Would you like to perform another calculation? (y/n): ");
        
        String contin = keyboard.next();
        String end = "";
        
        if("y".equals(contin) || "Y".equals(contin)){
            System.out.println("\n");
            System.out.println(menu());
        }
        
        return end;
    }
}
