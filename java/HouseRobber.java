package leetcode;

public class HouseRobber {
	public static void main(String[] args) {
		int[] input = {3,4,3,5};
		System.out.println(rob(input));
	}
	
    public static int rob(int[] nums) {
    	if(nums.length == 0)
    		return 0;
        int[] max = new int[2];
        for(int i = 0;i < nums.length;i++){
        	max[i%2] = max[(i+1)%2] > (max[i%2]+nums[i]) ? max[(i+1)%2] : (max[i%2]+nums[i]);
        }
        return max[(nums.length - 1)%2];
    }
}
