// basicCalculatorII.cpp

/**************************************
https://leetcode.com/problems/basic-calculator-ii/

Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.
**************************************/
#include <iostream>
#include <stack>

using namespace std;

// there are no '(' and ')' in the expression,
// so there are only two kind of priority ('*' and '/') or ('+' and '-')
// so we get '*' and '/' done in first turn and '+' and '-' in second turn
int calculate(string s){
	int res = 0;
	stack<int> sign;
	stack<int> nums;
	int flag = 0;

	// first turn 
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
	// second turn
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