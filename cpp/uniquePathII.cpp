// uniquePathII.cpp

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid){
	if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;

	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector< vector<int> > res(m, vector<int>(n, 0));
	res[0][0] = 1 - obstacleGrid[0][0];
	for(int i = 1;i < m;i++){
		if(obstacleGrid[i][0] == 0) res[i][0] = res[i-1][0];
	}
	for(int i = 1;i < n;i++){
		if(obstacleGrid[0][i] == 0) res[0][i] = res[0][i-1];
	}
	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			if(obstacleGrid[i][j] == 0) res[i][j] = res[i][j-1] + res[i-1][j];
		}
	}
	return res[m-1][n-1];
}

int main(){
	int a[] = {0, 0, 0},
		b[] = {0, 1, 0},
		c[] = {1, 0, 0};
	vector<int> va,vb,vc;
	va.assign(a, a+3);
	vb.assign(b, b+3);
	vc.assign(c, c+3);
	vector< vector<int> > matrix;
	matrix.push_back(va);
	matrix.push_back(vb);
	matrix.push_back(vc);
	cout << uniquePathsWithObstacles(matrix) << endl;
	return 0;
}