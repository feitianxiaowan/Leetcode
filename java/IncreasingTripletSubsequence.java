package leetcode;

public class IncreasingTripletSubsequence {
	public static void main(String[] args) {
		int[] input = {4,3,1,4};
		System.out.println(increasingTriplet(input));
	}
    public static boolean increasingTriplet(int[] nums) {
        int c1 = Integer.MAX_VALUE, c2 = Integer.MAX_VALUE;
        for (int i : nums)
        	// update the first number of the triplet
        	// if the first number have a better choice,it won't be modified until there a better second number
        	// c1 < nums[i] < c2
            if (i <= c1)
                c1 = i;
        	// update the second number of the triplet
        	// only when c1 <= nums[i] <= c2,which guarantee the first two number is increasing
            else if (i <= c2)
                c2 = i;
            else
                return true;
        return false;
    }
}
