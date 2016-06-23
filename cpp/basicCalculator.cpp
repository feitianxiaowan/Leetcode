// basicCalculator.cpp

#include <iostream>
#include <stack>
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


// the key is mataining the signature!
int calculate(string s){
	int res = 0;
	stack<int> sign;
    sign.push(1);sign.push(1);sign.push(1);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0'){
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