// basicCalculator.cpp

/**************************************
https://leetcode.com/problems/basic-calculator/

Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.
**************************************/

#include <iostream>
#include <stack>
/**************************************
<stack> has two main function: push() and pop()
can be replace by two <vector> function: push_back() and pop_back()
of course we can always build our own struct and function.
**************************************/
#include <vector>

using namespace std;

// int calculate(string s) {
//     int res = 0;
//     vector<int> sign(2, 1);
//     for (int i = 0; i < s.size(); ++i) {
//         char c = s[i];
//         if (c >= '0') {
//             int num = 0;
//             while (i < s.size() && s[i] >= '0') {
//                 num = 10 * num + s[i++] - '0';
//             }
//             res += sign.back() * num;
//             sign.pop_back();
//             --i;
//         }
//         else if (c == ')') sign.pop_back();
//         else if (c != ' ') sign.push_back(sign.back() * (c == '-' ? -1 : 1));
//     }
//     return res;
// }


// there are only '+' and '-' in the expression.
// the key is mataining the signature! a stack is the best choice.
int calculate(string s){
	int res = 0;
	stack<int> sign;// the stack is used to maintain current signature
    sign.push(1);sign.push(1);sign.push(1);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0'){// get the number
            int num = 0;
            while(i < s.size() && s[i] >= '0'){
                num = num * 10 + s[i++] - '0';
            }
            res += sign.top() * num;
            sign.pop();
            i--;
        }
        else if(s[i] == ')')  sign.pop();
        else if(s[i] == '+')  sign.push(sign.top());
        else if(s[i] == '(')  sign.push(sign.top());
        else if(s[i] == '-')  sign.push(sign.top() * -1);
	}
    return res;
}

int main(){
	string s = "(1-(4+55+2)-3) + (6+8)";
	cout << calculate(s) << endl;
	return 0;
}