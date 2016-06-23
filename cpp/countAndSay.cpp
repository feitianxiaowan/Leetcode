// LeetcodeOJ_countAndSay.cpp

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n){
	string formar = "1", rear = "";

	int follow, num;
	for(int i = 0;i < n;i++){
		follow = formar[0];
		num = 1;
		formar = rear;
		rear = "";
		// cout << num << ' ' << follow - '0' << endl;
		for(int j = 1;j < formar.size();j++){
			if(follow != formar[j]){
				// cout << num << ' ' << follow - '0' << endl;
				rear.append(1, '0'+num);
				rear.append(1, follow);
				follow = formar[j];
				num = 1;
			}
			else 
				num++;
		}
		// cout << num << ' ' << follow - '0' << endl;
		rear.append(1, '0'+num);
		rear.append(1, follow);
	}

	return rear;
}

int main(){
	int n = 2;
	cout << countAndSay(n) << endl;
	return 0;
}