package test3;

public class Test3 {
     public static double mystery_two(double[] x) {
     	double result = 1;
            
              for( int i = 0; i < x.length; i++ )  result *= x[i];

             return Math.pow(result, 1.0/x.length);
    		     }

    		     public static void main(String[] args) {
          double[] arr = { 4.3, 5.1, 6.8, 1.2, 0.4 };
                                      System.out.println("Result is: "+mystery_two(arr));
    		   }
   		}		




