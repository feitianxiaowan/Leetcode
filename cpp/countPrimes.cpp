// countPrimes.cpp

#include <iostream>
#include <math.h>

using namespace std;

int countPrimes(int n){
	if(n < 3)
		return 0;
	int *pnum = new int[n];
	int mid = floor(sqrt(n));
	for(int i = 2;i <= mid;i++){
		if(pnum[i] != 0)
			continue;
		else{
			for(int j = i + 1;j < n;j++){
				if(pnum[j] != 0)
					continue;
				else{
					if(j % i == 0)
						pnum[j] = 1;
				}
			}
		}
	}
	int count = 0;
	for(int i = 2;i < n;i++){
		if(pnum[i] == 0){
			count++;
		}
	}
	return count;
}

int main(){
	int n = 3;
	cout << countPrimes(n) << endl;
	return 0;
}