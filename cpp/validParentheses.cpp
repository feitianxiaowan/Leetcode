// validParentheses.cpp

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s){
	stack<char> pstack;

	for(int i = 0;i < s.length();i++){
		if(pstack.size() == 0)
			pstack.push(s[i]);
		else if(s[i] == ']' && pstack.top() == '[')
			pstack.pop();
		else if(s[i] == '}' && pstack.top() == '{')
			pstack.pop();
		else if(s[i] == ')' && pstack.top() == '(')
			pstack.pop();
		else
			pstack.push(s[i]);
	}
	
	return pstack.size() == 0;
}

int main(){
	string s = "]";
	cout << (isValid(s) ? "yes" : "no") << endl;
	return 0;
}