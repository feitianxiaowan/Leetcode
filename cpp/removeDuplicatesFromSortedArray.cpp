// removeDuplicatesFromSortedArray.cpp

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
	if(nums.size() <= 1) return nums.size();

	vector<int>::iterator ita = nums.begin(), itb = nums.begin() + 1;
	int count = 1;
	do{
		if(*ita != *itb){
			count++;
			ita = itb++;
		}
		else{
			nums.erase(itb);
		}
	}while(itb != nums.end());
	return count;
}

int main(){
	int nums[] = {1,2,2,3,4,5,6,6,6,7,8};
	vector<int> vnums;
	vnums.assign(nums, nums+11);
	cout << removeDuplicates(vnums) << endl;
	for(int i = 0;i < vnums.size();i++)
		cout << vnums[i] << ' ';
	return 0;
}
