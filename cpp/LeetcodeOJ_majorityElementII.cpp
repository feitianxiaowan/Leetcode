// LeetcodeOJ_majorityElementII.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums){
	int numa = 0x7fffffff,numb = 0x7fffffff;
	int counta = 0,countb = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == numa){
			counta++;
		}
		else if(nums[i] == numb){
			countb++;
		}
		else if(counta == 0){
			numa = nums[i];
			counta++;
		}	
		else if(countb == 0){
			numb = nums[i];
			countb++;
		}
		else{
			counta--;
			countb--;
		}
	}

	counta = countb = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == numa)
			counta++;
		else if(nums[i] == numb)
			countb++;
	}

	vector<int> result;
	if(counta > nums.size() / 3)
		result.push_back(numa);
	if(countb > nums.size() / 3)
		result.push_back(numb);
	return result;
}

int main(){
	int nums[] = {1,1,1,1,2,2,2,2,3,3};
	vector<int> vnums(nums,nums + 10);
	vector<int> result(majorityElement(vnums));
	for(int i = 0;i < result.size();i++)
		cout << result[i] << ' ';
	cout << endl;
}