#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int pre[60], obj[60], post[60];


void insert(int top, int tmp) {
	if (obj[top] > obj[tmp]) {
		if (pre[top] == top) pre[top] = tmp;
		else insert(pre[top], tmp);		
	}
	else {
		if (post[top] == top) post[top] = tmp;
		else insert(post[top], tmp);
	}

}


void output(int i) {
	if (pre[i] != i) output(pre[i]);
	cout << i << "...." << obj[i] << endl;
	if (post[i] != i) output(post[i]);
}	
	
	/*
	if (pre[i] == i) { cout << i << "...."<< obj[i] << endl; }
	else {
		output(pre[i]);
	}
	if (post[i] == i) { cout << i << "...." << obj[i] << endl; }
	else {
		output(post[i]);
	}*/ // pre[i]와 post[i] 모두 i인 경우 두 번 중복되어 출력 됨. (Binary tree 최하단부) 또한, 





int main() {
	string line;
	int count = 0;

	ifstream file("sorttest1.txt"); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open()) {
		while (getline(file, line)) {
			obj[count++] = stoi(line); // line은 string이기 때문에 int로 바꿀 필요
			
		}
		file.close(); // 열었던 파일을 닫는다. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	for (int i = 0; i < count; i++) {
		pre[i] = i;
		post[i] = i;
	}

	for (int i = 1; i < count; i++) {
		insert(0, i);

	}

	output(0);

	

	return 0;
}