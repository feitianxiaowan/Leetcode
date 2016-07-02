// letterCombinationsOfAPhoneNumber.cpp

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

// vector<string> letterCombinations(string digits){
// 	vector<string> res;
// 	for(int k = 0;k < 3 + (int)(digits[0]-'1')/6;k++){
// 		string temp = "a";
// 		temp[0] += (digits[0] - '0' - 2)*3 + k;
// 		res.push_back(temp);
// 	}
// 	for(int i = 1;i < digits.size();i++){
// 		int resize = res.size();
// 		for(int j = 0;j < resize;j++){
// 			if(digits[i] == '1') continue;
// 			if(digits[i] == '0'){
// 				for(int k = 0;k < resize;k++)
// 					res[k] += ' ';
// 				continue;
// 			}
// 			for(int k = 1;k < (3 + (digits[i]-'1')/6);k++){
// 				string temp = res[j];
// 				temp += 'a' + (digits[i] - '0' - 2)*3 + k;
// 				res.push_back((temp));
// 			}
// 			res[j] += 'a' + (digits[i] - '0' - 2)*3;
// 		}
// 	}
// 	return res;
// }

vector<string> letterCombinations(string digits){
	string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string> res;

	if(digits.size() == 0) return res;

	for(int k = 0;k < numap[digits[0]-'0'].size();k++){
		string temp = "";
		temp += numap[digits[0]-'0'][k];
		res.push_back(temp);
	}
	for(int i = 1;i < digits.size();i++){
		int resize = res.size();
		for(int j = 0;j < resize;j++){
			for(int k = 1;k < numap[digits[i]-'0'].size();k++){
				res.push_back(res[j] + numap[digits[i]-'0'][k]);
			}
			res[j] += numap[digits[i]-'0'][0];
		}

	}
	return res;
}	

int main(){
	string digits = "732";
	vector<string> res = letterCombinations(digits);
	for(int i = 0;i < res.size();i++)
		cout << res[i] << endl;
	return 0;
}