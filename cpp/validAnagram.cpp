// validAnagram.cpp

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(string s,string t){
	if(s.size() != t.size()) return false;
	if(s.size() == 0) return true;

	sort(s.begin(),s.end());
	sort(t.begin(),t.end());

	for(int i = 0;i < s.size();i++){
		if(s[i] != t[i]) return false;
	}
	return true;
}

int main(){
	string s = "anagram";
	string t = "nagaram";
	cout << (isAnagram(s,t) ? "yes" : "no") << endl;
}