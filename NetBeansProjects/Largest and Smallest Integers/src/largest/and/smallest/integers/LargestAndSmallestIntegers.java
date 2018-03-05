package largest.and.smallest.integers;

import java.util.Scanner;

public class LargestAndSmallestIntegers {

    public static void main(String[] args) {
        
        Scanner input = new Scanner ( System.in );
        
        int num1,
            num2,
            num3,
            num4,
            num5;
        
        System.out.println("Enter five numbers to find the smallest and largest numbers.");
        
        System.out.print("Number 1: ");
        num1 = input.nextInt();
        System.out.print("Number 2: ");
        num2 = input.nextInt();
        System.out.print("Number 3: ");
        num3 = input.nextInt();
        System.out.print("Number 4: ");
        num4 = input.nextInt();
        System.out.print("Number 5: ");
        num5 = input.nextInt();
        
        if(num1>num2&&num1>num3&&num1>num4&&num1>num5)
        {
            System.out.println("The largest number is " + num1);
        }
        
        if(num2>num1&&num2>num3&&num2>num4&&num2>num5)
        {
            System.out.println("The largest number is " + num2);
        }
        
        if(num3>num1&&num3>num2&&num3>num4&&num3>num5)
        {
            System.out.println("The largest number is " + num3);
        }
        
        if(num4>num1&&num4>num2&&num4>num3&&num4>num5)
        {
            System.out.println("The largest number is " + num4);
        }
        
        if(num5>num1&&num5>num2&&num5>num3&&num5>num4)
        {
            System.out.println("The largest number is " + num5);
        }
        
        if(num1<num2&&num1<num3&&num1<num4&&num1<num5)
        {
            System.out.println("The smallest number is " + num1);
        }
        
        if(num2<num1&&num2<num3&&num2<num4&&num2<num5)
        {
            System.out.println("The smallest number is " + num2);
        }
        
        if(num3<num1&&num3<num2&&num3<num4&&num3<num5)
        {
            System.out.println("The smallest number is " + num3);
        }
        
        if(num4<num1&&num4<num2&&num4<num3&&num4<num5)
        {
            System.out.println("The smallest number is " + num4);
        }
        
        if(num5<num1&&num5<num2&&num5<num3&&num5<num4)
        {
            System.out.println("The smallest number is " + num5);
        }
    }
    
}
