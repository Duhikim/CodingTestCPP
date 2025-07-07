#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	long long N, K;
	cin >> N >> K;
	
	if (N==2 && K==1) {
		cout << 1 << endl;
		return 0;
	}

	if (N != 1) {
		cout << -1 << endl;
		return 0;
	}

	
	for(int i=1; i<K; i++){
		cout << 1 << " ";
	} 		
	cout << 1 << endl;

	return 0;
}