// climbingStairs.cpp

#include <iostream>

using namespace std;

int climbStairs(int n){
	int *d = new int[n+1];
	d[0] = 1;
	d[1] = 1;
	for(int i = 2;i <= n;i++){
		d[i] = d[i-1] + d[i-2];
	}
	return d[n];
}

int main(){
	int n = 3;
	cout << climbStairs(n) << endl;
	return 0;
}