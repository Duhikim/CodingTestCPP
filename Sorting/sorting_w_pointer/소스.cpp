#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct record {
	int order;
	int obj;
	record* next;
};

record sortdata[60];
record* divsort(int top, int amount) {
	if (amount == 1) return &sortdata[top];
	else { 
		record* first =	divsort(top, amount / 2);
		record* second = divsort(top + (amount / 2), amount - amount / 2);

		record* temp; 
		if (first->obj > second->obj) { temp = first; first = second; second = temp; }
		
		//

		while (first->next != nullptr) {
			
			temp = (first+1);
			if (temp->obj < second->obj) { first = temp; }
			else { first->next = second; second->next = temp; second=(second+1); }
			if (second->next == nullptr) break;
		}
		
		first->next = second;
		return first;
	}
	

}

int main() {
	string line;
	int count = 0;

	ifstream file("sorttest1.txt"); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open()) {
		while (getline(file, line)) {
			sortdata[count].order = count;
			sortdata[count].obj = stoi(line); // line은 string이기 때문에 int로 바꿀 필요
			sortdata[count++].next = nullptr;
		}
		file.close(); // 열었던 파일을 닫는다. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}





	return 0;
}



/*
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
*/
