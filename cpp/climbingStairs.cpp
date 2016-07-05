// climbingStairs.cpp

/**************************************
https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
**************************************/

#include <iostream>

using namespace std;


// it is a Dynamic Programming problem, if you want to get to the stairs 'n'
// you need to get to 'n-1' or 'n-2' so d[n] = d[n-1] + d[n-2]
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