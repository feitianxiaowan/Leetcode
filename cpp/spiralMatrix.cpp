// spiralMatrix.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector< vector<int> >& matrix){
	vector<int> res;
	if(matrix.size() == 0) return res;
	int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
	while(up <= down && left <= right){
		for(int i = left;i <= right;i++)
			res.push_back(matrix[up][i]);
		up++;
		for(int i = up;i <= down;i++)
			res.push_back(matrix[i][right]);
		right--;
		if(up <= down){
			for(int i = right;i >= left;i--)
				res.push_back(matrix[down][i]);
			down--;
		}
		if(left <= right){
			for(int i = down;i >= up;i--)
				res.push_back(matrix[i][left]);
			left++;
		}
	}
	return res;
}

int main(){
	int a[] = {1, 2, 3};
		// b[] = {4, 5, 6},
		// c[] = {7, 8, 9};
	vector<int> va,vb,vc;
	va.assign(a, a+3);
	// vb.assign(b, b+3);
	// vc.assign(c, c+3);
	vector< vector<int> > matrix;
	matrix.push_back(va);
	// matrix.push_back(vb);
	// matrix.push_back(vc);
	// cout << matrix[2].size();
	// for(int i = 0;i < matrix.size();i++){
	// 	for(int j = 0;j < matrix[0].size();j++)
	// 		cout << matrix[i][j] << ' ';
	// 	cout << endl;
	// }
	vector<int> res = spiralOrder(matrix);
	for(int i = 0;i < res.size();i++)
		cout << res[i] << ' ';
	cout << endl;
}