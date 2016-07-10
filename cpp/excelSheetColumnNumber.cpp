// excelSheetColumnNumber.cpp

#include <iostream>

using namespace std;

int titleToNumber(string s){
	int res = 0;
	for(int i = 0;i < s.size();i++){
		res = res * 26 + (s[i] - 'A' + 1);
	}
	return res;
}

int main(){
	cout << titleToNumber("AB") << endl;
	return 0;
}