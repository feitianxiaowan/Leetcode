package leetcode;

public class MajorityElement {
	public static void main(String[] args) {
		int[] input = {1,2,3,1,1,2,1,1};
		System.out.println(majorityElement(input));
	}
	
	// algorithm "moore's voting"
    public static int majorityElement(int[] nums) {
        int majorPointer = 0;
        int majorCount = 0;
        for(int i = 0;i < nums.length;i++){
        	if(nums[majorPointer] == nums[i])
        		majorCount++;
        	else
        		majorCount--;
        	if(majorCount < 0){
        		majorPointer = i;
        		majorCount = 0;
        	}
        }
        return nums[majorPointer];
    }
}
