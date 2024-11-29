#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	
	int N, M;
	cin >> N >> M;
	vector<string> goormItem(N);
	for (int i = 0; i < N; i++) {
		cin >> goormItem[i];
	}	
	vector<string> friendItem(N);
	for (int i = 0; i < N; i++) {
		cin >> friendItem[i];
	}
	for (int idx = 0; idx < M; idx++) {
		string item1, item2;
		cin >> item1 >> item2;
		auto iter1 = find(goormItem.begin(), goormItem.end(), item1);
		auto iter2 = find(friendItem.begin(), friendItem.end(), item2);
		if (iter1 != goormItem.end()
			&& iter2 != friendItem.end()) {
			string temp = *iter1;
			goormItem.erase(iter1);
			goormItem.push_back(*iter2);
			friendItem.erase(iter2);
			friendItem.push_back(temp);
		}
	}
	sort(goormItem.begin(), goormItem.end());

	for (int i = 0; i < goormItem.size() - 1; i++) {
		cout << goormItem[i] << " ";
	} cout << goormItem[goormItem.size() - 1] << '\n';


	return 0;
}
