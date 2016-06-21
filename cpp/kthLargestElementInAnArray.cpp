// kthLargestElementInAnArray.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k){
	make_heap(nums.begin(),nums.end());
	for(int i = 0;i < k;i++)
		pop_heap(nums.begin(),nums.end()-i);
	return nums[nums.size() - k];
}

int main(){
	int nums[] = {3,2,1,5,6,4};
	vector<int> vnums;
	vnums.assign(nums,nums + 6);
	cout << findKthLargest(vnums,2) << endl;
}