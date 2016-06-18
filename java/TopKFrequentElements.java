package leetcode;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;

public class TopKFrequentElements {
	public static void main(String[] args) {
		int[] nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
		int k = 10;
		List<Integer> num = topKFrequent(nums, k);
		for(int i : num)
			System.out.print(i+" ");
	}
	
	// first we sort the array nums - O(nlogn)
	// then we count the continuely characters and find the top k frequent Elements - O(k*n)
    public static List<Integer> topKFrequent(int[] nums, int k) {
    	quickSort(nums, 0, nums.length - 1);
    	List<Integer> num = new ArrayList<Integer>();
    	List<Integer> count = new ArrayList<Integer>();
    	for(int i = 0;i < k;i++){
    		num.add(0);
    		count.add(0);
    	}
    	int headcursor = 0,tailcursor = 0;
    	int c = 0;
    	while(tailcursor < nums.length){
    		while(tailcursor < nums.length && nums[headcursor] == nums[tailcursor])
    			tailcursor++;
    		c = tailcursor - headcursor;
    		for(int i = 0;i < k;i++){
    			if(c > count.get(i)){
    				for(int j = k-1;j > i;j--){
    					count.set(j, count.get(j-1));
    					num.set(j, num.get(j-1));
    				}
    				count.set(i, c);
    				num.set(i, nums[headcursor]);
    				break;
    			}
    		}
    		headcursor = tailcursor;
    	}
		return num;
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
	
	
//	// using hash table - O(n)
//	public static List<Integer> topKFrequent(int[] nums, int k) {
//		 Hashtable<Integer, Integer> numbers = new Hashtable<Integer, Integer>();
//		 for(int i : nums){
//			 if(numbers.containsKey(i))
//				 numbers.put(i, numbers.get(i)+1);
//			 else
//				 numbers.put(i, 1);
//		 }
//		 
//	}
}
