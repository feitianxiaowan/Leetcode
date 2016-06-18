package leetcode;

public class IntegerBreak {
	public static void main(String[] args) {
		int input = 2;
		System.out.println(integerBreak(input));
	}
	
	// it is obviously the more 3 you get, the bigger the product is.
	// and 4 should be break into two 2s
    public static int integerBreak(int n) {
    	if(n < 2)
    		return 0;
    	if(n == 2)
    		return 1;
    	if(n == 3)
    		return 2;
        int p = n/3;
        int r = n%3;
        int maxProduct = 1;
        if(r == 1){
        	maxProduct *= 4;
        	p--;
        }
        else if(r == 2){
        	maxProduct *= 2;
        }
        for(int i = 0;i < p;i++){
        	maxProduct *= 3;
        }
        return maxProduct;
    }
}
