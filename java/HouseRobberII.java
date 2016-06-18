package leetcode;

public class HouseRobberII {
	public static void main(String[] args) {
		int[] input = {3,3};
		System.out.println(rob(input));
	}
	
    public static int rob(int[] nums) {
    	if(nums.length == 0)
    		return 0;
    	else if(nums.length == 1)
    		return nums[0];
        int[] max = new int[2];
        for(int i = 0;i < (nums.length - 1);i++){
        	max[i%2] = max[(i+1)%2] > (max[i%2]+nums[i]) ? max[(i+1)%2] : (max[i%2]+nums[i]);
        }
        int max1 = max[(nums.length - 2)%2];
        max[1] = max[0] = 0;
        for(int i = 1;i < nums.length;i++){
        	max[i%2] = max[(i+1)%2] > (max[i%2]+nums[i]) ? max[(i+1)%2] : (max[i%2]+nums[i]);
        }
        int max2 = max[(nums.length - 1)%2];
        return max2>max1 ? max2 : max1;
    }
}
