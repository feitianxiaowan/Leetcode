// uglyNumberII.cpp

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int nthUglyNumber(int n){
	int p1 = 0, p2 = 0, p3 =0;
	vector<int> uglynum;
	uglynum.push_back(1);
	for(int i = 0;i < n;i++){
		int nextUN = min(uglynum[p1]*2,min(uglynum[p2]*3,uglynum[p3]*5));
		uglynum.push_back(nextUN);
		// cout << nextUN << endl;
		if(nextUN == uglynum[p1] * 2)	p1++;
		if(nextUN == uglynum[p2] * 3)	p2++;
		if(nextUN == uglynum[p3] * 5)	p3++;
	}
	return uglynum[n-1];
}

int main(){
	cout << nthUglyNumber(10) << endl;
	return 0;
}