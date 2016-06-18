package leetcode;

import java.util.ArrayList;
import java.util.List;

public class LongestIncreasingSubsequence {
	public static void main(String[] args) {
		int[] input = {1,3,6,7,9,4,10,5,6};
		System.out.println(lengthOfLIS(input));
	}
    public static int lengthOfLIS(int[] nums) {
    	if(nums.length == 0)
    		return 0;
    	List<Integer> subseq = new ArrayList<Integer>();
    	subseq.add(nums[0]);
        for(int i = 1;i < nums.length;i++){
        	for(int j = 0;j < subseq.size();j++){
        		System.out.print(subseq.get(j)+" ");
        	}
        	System.out.println();
        	for(int j = 0;j < subseq.size();j++){
        		if(subseq.get(j) >= nums[i]){
        			subseq.set(j, nums[i]);
        			break;
        		}
        		if(j == subseq.size()-1){
	        		subseq.add(nums[i]);
	        		break;
	        	}
        	}
        }
        return subseq.size();
    }
}
