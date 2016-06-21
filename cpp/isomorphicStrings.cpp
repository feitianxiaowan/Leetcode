// isomorphicStrings.cpp

#include <iostream>
// #include <ext/hash_map> // Mac, for Windows or Linux just use #include <hash_map>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t){
	// __gnu_cxx::hash_map<char,char> cmap;
	// __gnu_cxx::hash_map<char,char> tmap;
	unordered_map<char,char> cmap;
	unordered_map<char,char> tmap;
	bool result = true;

	if(s.size() != t.size())
		return false;

	for(int i = 0;i < s.size();i++){
		if( cmap.find(s[i]) == cmap.end() ){
			cmap[s[i]] = t[i];
		}
		else if( cmap[s[i]] != t[i] ){
			result = false;
			break;
		}

		if( tmap.find(t[i]) == tmap.end() ){
			tmap[t[i]] = s[i];
		}
		else if( tmap[t[i]] != s[i] ){
			result = false;
			break;
		}
	}

	return result;
}


int main(){
	string s = "bab";
	string t = "aba";

	cout << (isIsomorphic(s, t) ? "yes" : "no") << endl;

	return 0;
}