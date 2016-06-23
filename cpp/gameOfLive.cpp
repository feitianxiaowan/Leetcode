// LeetcodeOJ_gameOfLive.cpp

#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int> >& board) {
	int m = board.size();
	int n = m ? board[0].size() : 0;// Details!

	int dx[8] = {-1,-1,-1,0,0,1,1,1};// How to traverse eight position!
	int dy[8] = {-1,0,1,-1,1,-1,0,1};

    for(int i = 0;i < m;i++){
    	for(int j = 0;j < n;j++){
    		int surround = 0;
    		for(int k = 0;k < 8;k++){
    			int x = i + dx[k];
    			int y = j + dy[k];
    			if(x >= 0 && x < m && y >= 0 && y < n)
    				surround += board[x][y] % 2;
    		}
    		if((board[i][j] && surround == 2) || surround == 3)
    			board[i][j] += 2;
    	}
    }
		for(int i = 0;i < m;i++)
    	for(int j = 0;j < n;j++)
    		board[i][j] >>= 1;
}

int main(){
	int status[4][4] = {
		1,0,0,1,
		1,1,0,1,
		0,1,1,0,
		0,0,1,0
	} ;
	vector<vector<int> > vstatus(4,vector<int>(4,0));
	for(int i = 0;i < 4;i++)
		for(int j =0;j < 4;j++)
			vstatus[i][j] = status[i][j];

	gameOfLife(vstatus);

	for(int i = 0;i < 4;i++){
		for(int j =0;j < 4;j++){
			cout << vstatus[i][j] <<',';
		}
		cout << endl;
	}

}