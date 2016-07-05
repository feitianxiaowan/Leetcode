// compareVersionNumber.cpp

/**************************************
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
**************************************/

#include <iostream>
#include <string>
/**************************************
there
**************************************/

using namespace std;

int compareVersion(string version1, string version2){
	int v1h, v2h;
	v1h = v2h = 0;
	int v1p = 0;
	while(v1p < version1.size() && version1[v1p] != '.'){
		v1h = v1h * 10 + (version1[v1p] - '0');
		v1p++;
	}
	int v2p = 0;
	while(v2p < version2.size() && version2[v2p] != '.'){
		v2h = v2h * 10 + (version2[v2p] - '0');
		v2p++;
	}
	int stopflag = 0;
	if(v1p < version1.size()){
		stopflag = 1;
		v1p++;
	}
	if(v2p < version2.size()){
		stopflag = 1;
		v2p++;
	}
	// cout << v1h << ' ' << v2h << endl;
	// cout << version1.substr(v1p) << ' ' << version2.substr(v2p) << endl;
	if(v1h > v2h) return 1;
	else if(v1h < v2h) return -1;
	else if(stopflag == 1) return compareVersion(version1.substr(v1p), version2.substr(v2p)); 
	else return 0;  
}

int main(){
	string version1 = "01";
	string version2 = "1";
	cout << compareVersion(version1,version2) << endl;
}