// LeetcodeOJ_findTheDuplicateNumber.cpp

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums){
	int low = 1;
	int up = nums.size() - 1;
	int mid = (low + up) / 2;

	int upcount = 0;// count the number of nums larger than mid.
	int lowcount = 0;
	while(low != up){
		for(int i = 0;i <nums.size();i++){
			upcount += (nums[i] > mid && nums[i] <= up) ? 1 : 0;
			lowcount += (nums[i] < mid && nums[i] >= low) ? 1 : 0;
		}
		if(up - mid < upcount){
			low = mid + 1;
			mid = (low + up) / 2;
		}
		else if(mid - low < lowcount){
			up = mid - 1;
			mid = (low + up) / 2;
		}
		else 
			return mid;
		
		upcount = lowcount = 0;
	}
	return low;
}

int main(){
	int nums[8] = {1,2,3,4,5,6,6,7};
	vector<int> vnums(nums,nums + 8);
	cout << findDuplicate(vnums) << endl;
}