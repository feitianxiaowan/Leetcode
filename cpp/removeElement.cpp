// removeElement.cpp

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val){
	if(nums.size() == 0) return 0;
	vector<int>::iterator it = nums.begin();
	do{
		if(*it == val){
			nums.erase(it);
		}
		else 
			it++;
	}while(it != nums.end());
	return nums.size();
}

int main(){
	int nums[] = {1,2,2,3,4,5,6,6,6,7,8};
	vector<int> vnums;
	vnums.assign(nums, nums+11);
	cout << removeElement(vnums, 6) << endl;
	for(int i = 0;i < vnums.size();i++){
		cout << vnums[i] << ' ';
	}
	return 0;
}