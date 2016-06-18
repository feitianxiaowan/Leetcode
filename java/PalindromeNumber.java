package leetcode;

public class PalindromeNumber {
	public static void main(String[] args) {
		int input = 1357531;
		System.out.println(new PalindromeNumber().isPalindrome(input));
	}
    public boolean isPalindrome(int x) {
    	if(x < 0)
    		return false;
    	else if(x == 0)
    		return true;
    	else{
    		// get the length of the "x"
    		int length = 1000000000;
    		while(x/length == 0)
    			length /= 10;
    		while(x > 0){
	    		if(x/length != x%10){
	    			return false;
	    		}
	    		x %= length;
    			x /= 10;
    			length /= 100;
	    	}
    		return true;
    	}
    }
}
