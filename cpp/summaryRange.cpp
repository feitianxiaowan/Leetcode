// LeetcodeOJ_summaryRange.cpp

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> summaryRanges(vector<int>& nums){
    int begin = nums[0],end;
    vector<string> result;
    stringstream ss;
    string tempa,tempb,tempc = "->";

    for(int i = 1;i < nums.size();i++){
    	if(nums[i] != nums[i-1] + 1){
            // cout << nums[i] << endl;
    		end = nums[i-1];
    		if(begin < end){
                ss << begin;
                ss >> tempa;
                ss << end;
                ss >> tempb;
    			result.push_back(tempa + "->" + tempb);
                cout << tempa + tempc + tempb;
            }
    		else{
                ss << begin;
                ss >> tempa;
    			result.push_back(tempa);
            }
    		begin = nums[i];
    	}
    }
    end = nums[nums.size()-1];
	if(begin < end){
        ss << begin;
        ss >> tempa;
        ss << end;
        ss >> tempb;
        result.push_back(tempa + "->" + tempb);
    }
    else{
        ss << begin;
        ss >> tempa;
        result.push_back(tempa);
    }
    return result;
}

int main(){
	int nums[] = {0,1,2,4,5,7};
	vector<int> vnums(nums,nums+6);
	vector<string> result = summaryRanges(vnums);
	// for(int i = 0;i < result.size();i++)
	// 	cout << result[i] << endl;
}