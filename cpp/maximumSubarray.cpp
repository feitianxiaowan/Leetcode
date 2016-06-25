// maximumSubarray.cpp

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums){
	if(nums.size() == 0)	return 0;

	int maxSum = nums[0], cSum = nums[0];
	for(int i = 1;i < nums.size();i++){
		if(cSum <= 0)	cSum = nums[i];
		else  cSum += nums[i];

		if(cSum > maxSum)	maxSum = cSum; 
	}

	return maxSum;
}

int main(){
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> vnums;
	vnums.assign(nums, nums+1);
	cout << maxSubArray(vnums) << endl;
	return 0;
}