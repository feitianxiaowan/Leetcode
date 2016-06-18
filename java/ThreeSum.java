package leetcode;

import java.util.ArrayList;
import java.util.List;

public class ThreeSum {
	public static void main(String[] args) {
		int[] nums = {0,0};
		List<List<Integer>> output = threeSum(nums);
		for(int i = 0;i < output.size();i++)
			System.out.println(" "+output.get(i).get(0)+" "+output.get(i).get(1)+" "+output.get(i).get(2));
	}
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> output = new ArrayList<List<Integer>>();
        quickSort(nums, 0, nums.length - 1);
        int i = 0,j = 0,k = 0;
        for(;i < nums.length;i++){
        	while(i > 0&&i < nums.length&&nums[i] == nums[i-1])
        		i++;
        	j = i + 1;
        	k = nums.length - 1;
        	while(j < k){
        		if(nums[j]+nums[k]+nums[i] < 0)
            		j++;
            	else if(nums[j]+nums[k]+nums[i] > 0)
            		k--;
            	else{
                    List<Integer> oneSolution = new ArrayList<Integer>();
            		oneSolution.add(nums[i]);
            		oneSolution.add(nums[j]);
            		oneSolution.add(nums[k]);
            		output.add(oneSolution);
            		while(j < k&&nums[j] == nums[j+1])
            			j++;
            		j++;
            	}
        	}
        }
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
