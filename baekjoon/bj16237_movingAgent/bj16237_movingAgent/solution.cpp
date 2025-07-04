#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool debug = 
false;
//true;

void input(vector<int>& burdens);
int solution(const vector<int>& burdens, vector<int>& remain);

int main() {

	if (debug) cout << "<<Debug mode>>" << '\n';

	do {		
		vector<int> burdens(6, 0);
		input(burdens);
		vector<int> remain = burdens;

		cout << solution(burdens, remain) << '\n';

	} while (debug);
	
	return 0;
}

void input(vector<int>& burdens) {	
	for (int i = 1; i <= 5; i++) {		
		cin >> burdens[i];		
	}
}

int solution(const vector<int>& burdens, vector<int>& remain) {
	int answer = burdens[5] + burdens[4];
	remain[5] = remain[4] = 0;
	remain[1] -= burdens[4];
	if (remain[1] < 0) remain[1] = 0;

	int idx, totalWeight;
	while (remain[1] || remain[2] || remain[3]) {
		answer++;
		totalWeight = 0;
		idx = 3;
		while (true) {
			while (remain[idx] && totalWeight + idx <= 5) {
				totalWeight += idx;
				remain[idx]--;
			}
			if (totalWeight == 5 || idx == 1) {
				break;
			}
			idx--;
		}
	}
	return answer;
}