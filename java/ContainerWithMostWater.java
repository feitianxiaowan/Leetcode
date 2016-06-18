package leetcode;

public class ContainerWithMostWater {
	public static void main(String[] args) {
		int[] input = {2,2,3,2,4,1};
		System.out.println(new ContainerWithMostWater().maxArea(input));
	}
	
	// we are going to use two cursor -- a head cursor moving toward the tail, and a tail cursor moving toward the head
	// it is obviously that you should move the cursor with lower height at a time and two cursor will meat at mid
	// so the proble can be complete at O(n)
    public int maxArea(int[] height) {
    	int i = 0,j = height.length - 1;
    	int maxArea = (height[i]<height[j]?height[i]:height[j]) * (j-i);
    	int temp = 0;
    	while(i < j){
    		while(height[i] <= height[j]&&i < j){
    			i++;
    			temp = (height[i]<height[j]?height[i]:height[j]) * (j-i);
    			if(temp > maxArea)
    				maxArea = temp;
    		}
    		while(height[i] >= height[j]&&i < j){
    			j--;
    			temp = (height[i]<height[j]?height[i]:height[j]) * (j-i);
    			if(temp > maxArea)
    				maxArea = temp;
    		}
    	}
        return maxArea;
    }
}
