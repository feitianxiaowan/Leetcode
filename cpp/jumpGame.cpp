// jumpGame.cpp

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool canJump(vector<int>& nums){
	int jump = 0;
	for(int i = 0;i < nums.size();i++){
		jump = max(jump - 1, nums[i]);
		if(jump <= 0 && i != nums.size() - 1) return false;
	}
	return true;
}

int main(){
	int nums[] = {1,2,2,0,0,2,0,1};
	vector<int> vNums;
	vNums.assign(nums, nums+8);
	cout << canJump(vNums) << endl;
	return 0;
}