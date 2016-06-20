// intersectOfTwoArraysII.cpp

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
	vector<int> result;
	return result;
}

int main(){
	int num1[] = {1, 2, 2, 1};
	int num2[] = {2, 2};
	vector<int> nums1, nums2;
	nums1.assign(num1, num1 + 4);
	nums2.assign(num2, num2 + 2);

	vector<int> result;
	result = intersect(nums1,nums2);
	for(int i = 0;i < result.size();i++)
		cout << result[i] << ' ';
	cout << endl;

	return 0;
}