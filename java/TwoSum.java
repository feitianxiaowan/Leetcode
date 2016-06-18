package leetcode;

public class TwoSum {
	public static void main(String[] args) {
		int[] nums = {3,2,4};
		int target = 6;
		int[] output = twoSum(nums, target);
		System.out.println(output[0]);
		System.out.println(output[1]);
	}
	
	// we are trying to find two number in the array whose sum equal to the target
	// first we sort the array using "quicksort" - O(nlogn)
	// then we use two cursor one start from the head while the other start from the tail
	// if nums[headcursor] + nums[tailcursor] > target, we need a larger number so headcursor++...
	// final we will find the nums[headcursor] + nums[tailcursor] = target
    public static int[] twoSum(int[] nums, int target) {
        int i = 0;
        int j = nums.length - 1;
        int[] numsBackup = new int[nums.length];
        for(int k = 0;k <nums.length;k++)
        	numsBackup[k] = nums[k];
        quickSort(nums, i, j);
        while(i < j){
        	if(nums[i]+nums[j] < target)
        		i++;
        	else if(nums[i]+nums[j] > target)
        		j--;
        	else
        		break;
        }
        // find the original position of the two numbers
        int a = 0,b = 0;
        boolean flaga = true,flagb = true;
        for(int k = 0;k < nums.length;k++){
        	if(numsBackup[k] == nums[i]&&flaga)
        		a = k;
        	if(numsBackup[nums.length - 1 - k] == nums[j]&&flagb)
        		b = nums.length - 1 - k;
        }
        int[] output = {a,b};
        return output;
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
