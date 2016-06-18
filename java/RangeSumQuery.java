package leetcode;

public class RangeSumQuery {
	public static void main(String[] args) {
		int[] nums = {-2, 0, 3, -5, 2, -1};
		NumArray na = new NumArray(nums);
		System.out.println(na.sumRange(0, 5));
	}
}
class NumArray {
	int[] preSum;
	
    public NumArray(int[] nums) {
        preSum = new int[nums.length+1];
        preSum[0] = 0;
        for(int i = 0;i < nums.length;i++){
        	preSum[i+1] = preSum[i] + nums[i];
//        	System.out.print(preSum[i]+" ");
        }
    }

    public int sumRange(int i, int j) {
        return preSum[j+1] - preSum[i];
    }
}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);