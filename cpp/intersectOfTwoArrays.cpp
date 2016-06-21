// intersectOfTwoArrays.cpp

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	vector<int> result;

	map<int,int> nums;
	for(int i = 0;i < nums1.size();i++){
		if( nums.find(nums1[i]) == nums.end() ){
			// nums.insert(pair<int,int>())
			nums[nums1[i]] = 1;
		}
		else{
			nums[nums1[i]] += 1;
		}
	}
	for(int j = 0;j < nums2.size();j++){
		if(nums[nums2[j]] != 0){
			result.push_back(nums2[j]);
			nums[nums2[j]] = 0;
		}
	}

	return result;
}

int main(){
	int num1[] = {1, 2, 2, 1};
	int num2[] = {2, 2};
	vector<int> nums1, nums2;
	nums1.assign(num1, num1 + 4);
	nums2.assign(num2, num2 + 2);

	vector<int> result;
	result = intersection(nums1, nums2);
	for(int i = 0;i < result.size();i++)
		cout << result[i] << ' ';
	cout << endl;

	return 0;
}