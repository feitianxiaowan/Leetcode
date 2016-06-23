// spiralMatrixII.cpp

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generateMatrix(int n){
	vector< vector<int> > res(n, vector<int>(n, 0));
	int up = 0, down = n - 1, left = 0, right = n - 1;
	int count = 1;
	while(up <= down && left <= right){
		for(int i = left;i <= right;i++)
			res[up][i] = count++;
		up++;
		for(int i = up;i <= down;i++)
			res[i][right] = count++;
		right--;
		if(up <= down){
			for(int i = right;i >= left;i--)
				res[down][i] = count++;
			down--;
		}
		if(left <= right){
			for(int i = down;i >= up;i--)
				res[i][left] = count++;
			left++;
		}
	}
	return res;
}

int main(){
	int n = 1;
	vector< vector<int> > res = generateMatrix(n);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[0].size();j++)
			cout << res[i][j] << '\t';
		cout << endl;
	}
}

