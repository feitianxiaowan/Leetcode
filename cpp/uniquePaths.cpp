// uniquePaths.cpp

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n){
	if(m == 0 || n == 0) return 0;
	vector< vector<int> > res(m, vector<int>(n,1));
	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			res[i][j] = res[i][j-1] + res[i-1][j];
		}
	}
	return res[m-1][n-1];
}

int main(){
	int m = 3, n = 2;
	cout << uniquePaths(m,n) << endl;
	return 0;
}