package leetcode;

public class ThreeSumCloest {
	public static void main(String[] args) {
		int[] input = {0,0,0};
		int target = 1;
		System.out.println(threeSumClosest(input, target));
	}
    public static int threeSumClosest(int[] nums, int target) {
        quickSort(nums, 0, nums.length - 1);
    	int minDiffSum = nums[0]+nums[1]+nums[2];
        int i = 0,j = 0,k = 0;
        for(;i < nums.length;i++){
        	j = i + 1;
        	k = nums.length - 1;
        	while(j < k){
        		if(Math.abs(minDiffSum - target) > Math.abs(target - (nums[j]+nums[k]+nums[i])))
        			minDiffSum = nums[j]+nums[k]+nums[i];
        		if(target - (nums[j]+nums[k]+nums[i]) < 0)
            		k--;
            	else if(target - (nums[j]+nums[k]+nums[i]) > 0)
            		j++;
            	else
            		return nums[j]+nums[k]+nums[i];
        	}
        }
        return minDiffSum;
    }
	public static void quickSort(int[] input,int start,int end){
		if(start >= end)
			return;
		int reference = input[end];
		int smallerCursor = start - 1;
		int cursor = start;
		int temp = 0;
		for(;cursor < end;cursor++){
			if(input[cursor] <= reference){
				smallerCursor++;
				temp = input[smallerCursor];
				input[smallerCursor] = input[cursor];
				input[cursor] = temp;
			}
		}
		smallerCursor++;
		temp = input[end];
		input[end] = input[smallerCursor];
		input[smallerCursor] = temp;
		quickSort(input, start, smallerCursor - 1);
		quickSort(input, smallerCursor + 1, end);
	}
}
