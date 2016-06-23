// gasStation.cpp

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
	int totalGas = 0, totalCost = 0;
	for(int i = 0;i < gas.size();i++){
		totalGas += gas[i];
		totalCost += cost[i];
	}
	if(totalGas < totalCost) return -1;

	int min = 0, minValue = 0;
	int tankValue = 0;
	for(int i = 1;i < gas.size();i++){
		tankValue += gas[i - 1] - cost[i -1];
		cout << i << ' ' << tankValue << endl;
		if(minValue > tankValue){
			minValue = tankValue;
			min = i;
		}
	}
	return min;
}

int main(){
	int gas[] = {1,2,3,3};
	int cost[] = {2,1,5,1};
	vector<int> vGas, vCost;
	vGas.assign(gas, gas + 4);
	vCost.assign(cost, cost + 4);
	cout << canCompleteCircuit(vGas,vCost) << endl;
	return 0;
}