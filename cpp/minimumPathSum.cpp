// minimumPathSum.cpp

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector< vector<int> >& grid){
	if(grid.size() == 0 && grid[0].size() == 0) return 0;

	vector< vector<int> > res(grid.size(), vector<int>(grid[0].size(), 0x7fffffff));
	res[0][0] = grid[0][0];
	for(int i = 1;i < grid.size();i++)
		res[i][0] = res[i-1][0] + grid[i][0];
	for(int i = 1;i < grid[0].size();i++)
		res[0][i] = res[0][i-1] + grid[0][i];
	for(int i = 1;i < grid.size();i++){
		for(int j = 1;j < grid[0].size();j++){
			res[i][j] = (res[i-1][j] > res[i][j-1] ? res[i][j-1] : res[i-1][j]) + grid[i][j];
		}
	}

	return res[grid.size() - 1][grid[0].size() - 1];
}

int main(){
	int a[] = {1, 2, 3},
		b[] = {4, 5, 6},
		c[] = {7, 8, 9};
	vector<int> va,vb,vc;
	va.assign(a, a+3);
	vb.assign(b, b+3);
	vc.assign(c, c+3);
	vector< vector<int> > matrix;
	matrix.push_back(va);
	matrix.push_back(vb);
	matrix.push_back(vc);
	cout << minPathSum(matrix) << endl;
	return 0;
}