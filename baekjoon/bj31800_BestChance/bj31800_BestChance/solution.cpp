#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;

	vector<int> profits(N);
	vector<int> costs(N);
	vector<int> opportunities(N);
	vector<int> netProfits(N);

	for (int i = 0; i < N; ++i) {
		cin >> profits[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> costs[i];
	}

	int maxProfitFirst=0, maxProfitSecond=0;
	for (int i = 0; i < N; ++i) {
		if (profits[i] > maxProfitFirst) {
			maxProfitSecond = maxProfitFirst;
			maxProfitFirst = profits[i];
		}
		else if (profits[i] > maxProfitSecond) {
			maxProfitSecond = profits[i];
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (profits[i] != maxProfitFirst) {
			opportunities[i] = maxProfitFirst - costs[i];
		}
		else{
			opportunities[i] = maxProfitSecond - costs[i];
		}
	}

	for(int i=0; i < N; ++i) {
		netProfits[i] = profits[i] - costs[i] - opportunities[i];
	}

	for (int i = 0; i < N - 1; i++) {
		cout << netProfits[i] << " ";
	} cout << netProfits[N - 1] << endl;

	return 0;
}