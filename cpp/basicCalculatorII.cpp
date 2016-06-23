// basicCalculatorII.cpp

#include <iostream>
#include <stack>

using namespace std;

int calculate(string s){
	int res = 0;
	stack<int> sign;
	stack<int> nums;
	int flag = 0;

	sign.push(1);
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0'){
			int num = 0;
			while(i < s.size() && s[i] >= '0'){
				num = num * 10 + s[i++] - '0';
			}
			i--;
			if(flag == 1){
				num *= nums.top();
				nums.pop();
			}
			else if(flag == 2){
				num = nums.top() / num;
				nums.pop();
			}
			nums.push(num);
			flag = 0;
		}
		else if(s[i] == '*') flag = 1;
		else if(s[i] == '/') flag = 2;
		else if(s[i] == '+') sign.push(1);
		else if(s[i] == '-') sign.push(-1);
	}
	while(!nums.empty()){
		res += nums.top() * sign.top();
		nums.pop();
		sign.pop();
	}

	return res;
}

int main(){
	string s;
	// s = "3 + 23*2 - 5 / 5";
	s = "0/1";
	cout << calculate(s) << endl;
	return 0;
}