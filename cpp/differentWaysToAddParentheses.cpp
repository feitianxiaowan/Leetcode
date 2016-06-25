// differentWaysToAddParentheses.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> diffWaysToCompute(string input){
	vector<int> res;
	for(int i = 0;i < input.size();i++){
		if(input[i] < '0'){
			vector<int> tempa,tempb;
			tempa = diffWaysToCompute(input.substr(0,i));
			tempb = diffWaysToCompute(input.substr(i+1));
			for(int j = 0;j < tempa.size();j++){
				for(int k = 0;k < tempb.size();k++){
					if(input[i] == '+') res.push_back(tempa[j] + tempb[k]);
					else if(input[i] == '-') res.push_back(tempa[j] - tempb[k]);
					else if(input[i] == '*') res.push_back(tempa[j] * tempb[k]);
				}
			}
		}
		else if(i == 0){
			int num = 0;
			while(i < input.size() && input[i] >= '0'){
				num = num * 10 + input[i] - '0';
				i++;
			}
			if(i == input.size())
				res.push_back(num);
			i--;
		}
	}
	return res;
}

int main(){
	string s = "2*3-4*5";
	vector<int> res = diffWaysToCompute(s);
	cout << "Ans: ";
	for(int i = 0;i < res.size();i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}