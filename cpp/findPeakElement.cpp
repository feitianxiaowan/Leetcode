// findPeakElement.cpp

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums){
	if(nums.size() <= 1) return 0;

	for(int i = 1;i < nums.size();i++){
		if(nums[i] < nums[i-1])
			return i-1;
	}
	return nums.size() - 1;
}

int main(){
	int nums[] = {1,3,4,2,1};
	vector<int> vnums;
	vnums.assign(nums, nums+5);
	cout << findPeakElement(vnums) << endl;
	return 0;
}