package leetcode;

public class PerfectSquares {
	int numSquars[];
	
	public static void main(String[] args) {
		int input = 25;
		PerfectSquares ps = new PerfectSquares();
		int output = ps.numSquares(input);
		System.out.println(output);
	}
	
    public int numSquares(int n) {
        numSquars = new int[n+1];
        return getNumSquars(n);
    }
    private int  getNumSquars(int n) {
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		if(numSquars[n] != 0)
			return numSquars[n];
		
		int numSquar = Integer.MAX_VALUE;
		int temp = 0;
		int i = (int)Math.floor(Math.sqrt(n));
		while(i > 0){
			temp = getNumSquars(n - i*i);
			if(numSquar > temp + 1)
				numSquar = temp + 1;
			i--;
		}
		numSquars[n] = numSquar;
		return numSquar;
	}
}
