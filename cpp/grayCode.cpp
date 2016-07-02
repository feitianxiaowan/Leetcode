// grayCode.cpp

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> grayCode(int n){
	vector<int> res(1 << n, 0);
	res[1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = (1 << (i-1));j < (1 << i);j++){
			res[j] = res[(1 << i) - j - 1] + (1 << (i - 1));
		}
	}
	return res;
}

int main(){
	vector<int> res;
	res = grayCode(5);
	for(int i = 0;i < res.size();i++)
		cout << res[i] << endl;
	return 0;
}