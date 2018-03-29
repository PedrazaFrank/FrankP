package test;

public class Test {

    public static int mystery_one(int x, int y) {
	int result = 0;
	for( int i = 0; i < x; i++ )
		for( int j = 0; j < y; j += 2 ) {
			System.out.printf("result=%d, i=%d, j=%d\n",result,i,j);
			result += ( i + 1 )*( j + 2);
	}
	return result;
}

    
    public static void main(String[] args) {
       System.out.println(mystery_one(2,7));
    }

}
