// searchA2DMatrixII.cpp

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector< vector<int> >& matrix, int target){
	if(matrix.size() == 0 || matrix[0].size() == 0) return false;

	int i = 0;
	while(i < matrix.size() && matrix[i][0] <= target){
		// cout << i << '\t';
		int j = 0, k = matrix[0].size() - 1;
		while(j <= k){
			// cout << (j+k)/2 << ' ';
			if(matrix[i][(j+k)/2] == target) return true;
			else if(matrix[i][(j+k)/2] < target) j = (j+k)/2 + 1;
			else k = (j+k)/2 - 1;
		}
		// cout << endl;
		i++;
	}

	return false;
}

int main(){
	// int a[] = {1, 2, 3},
	// 	b[] = {4, 5, 6},
	// 	c[] = {7, 8, 9};
	int a[] = {5};
	// int a[] = {1, 4},
	// 	b[] = {2, 5};
	vector<int> va,vb,vc;
	va.assign(a, a+3);
	// vb.assign(b, b+3);
	// vc.assign(c, c+3);
	vector< vector<int> > matrix;
	matrix.push_back(va);
	// matrix.push_back(vb);
	// matrix.push_back(vc);
	cout << (searchMatrix(matrix, 7) ? "true" : "false") << endl;
	return 0;
}