// superUglyNum.cpp

#include <iostream>
#include <vector>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes){
	int *pn = new int[primes.size()];
	for(int i = 0;i < primes.size();i++)
		pn[i] = 0;
	vector<int> superUglynum;
	superUglynum.push_back(1);

	for(int i = 0;i < n;i++){
		int nextSUN = 0x7fffffff;
		for(int j = 0;j < primes.size();j++){
			if(nextSUN > superUglynum[pn[j]] * primes[j]){
				nextSUN = superUglynum[pn[j]] * primes[j];
			}
		}
		superUglynum.push_back(nextSUN);
		// cout << nextSUN << endl;
		for(int j = 0;j < primes.size();j++){
			if(nextSUN == superUglynum[pn[j]] * primes[j]){
				pn[j]++;
			}
		}
	}

	return superUglynum[n-1];
}

int main(){
	int primes[] = {2, 7, 13, 19};
	vector<int> vprimes;
	vprimes.assign(primes, primes + 4);
	cout << nthSuperUglyNumber(10, vprimes);
	return 0;
}