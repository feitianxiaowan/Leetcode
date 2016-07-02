// decodeWays.cpp

#include <iostream>

using namespace std;

// if there is no '0' it can be good answer
// int numDecodings(string s){
// 	if(s.size() == 0) return 0;
// 	if(s.size() == 1) return 1;

// 	int res = 0;
// 	res += numDecodings(s.substr(1));
// 	if((s[0]-'0')*10 + s[1]-'0' <= 26) res += numDecodings(s.substr(2));
// 	return res;
// }

int numDecodings(string s){
	if(s.size() == 0 || s[0] == '0') return 0;
	if(s.size() == 1) return 1;

	int *res = new int[s.size()+1];
	res[0] = 1; res[1] = 1;
	for(int i = 2;i <= s.size();i++){
		res[i] = 0;
		if( s[i-1] != '0')
			res[i] += res[i-1];
		if( (((s[i-2]-'0')*10 + s[i-1]-'0') >= 10) && (((s[i-2]-'0')*10 + s[i-1]-'0') <= 26) ) 
			res[i] += res[i-2];
	}

	return res[s.size()];
}

int main(){
	cout << numDecodings("100") << endl;
	return 0;
}