// containDuplication.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums){
	if(nums.size() == 0) return false;
	sort(nums.begin(), nums.end());
	for(int i = 0;i < nums.size() - 1;i++){
		if(nums[i] == nums[i+1]) return true;
	}
	return false;
}

int main(){
	int nums[] = {1,2,3,1};
	vector<int> vnums; vnums.assign(nums, nums+4);
	cout << ( containsDuplicate(vnums) ? "yes" : "no" ) << endl;
	return 0;
}