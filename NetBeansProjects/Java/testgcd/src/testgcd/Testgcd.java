/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testgcd;
import java.util.Scanner;

/**
 *
 * @author Frankie
 */
public class Testgcd {

    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
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
        System.out.println("The GCD is "+gcd);
}
}
