package leetcode;

public class CountingBits {
	public static void main(String[] args) {
		int input = 10;
		int[] output = countBits(input);
		for(int i = 0;i < output.length;i++)
			System.out.print(output[i]);
	}
	
	// we can get the number of '1's of i with the floor(i/2)'s
    public static int[] countBits(int num) {
        int[] output = new int[num+1];
        output[0] = 0;
        for(int i = 1;i <= num;i++)
        	output[i] = i%2 + output[i/2];
        
        return output;
    }
}
