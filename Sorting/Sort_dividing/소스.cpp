#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int pre[100], number[100], post[100];

int merge(int first, int second){
	if (first == post[first] && second == post[second]) {
		if (number[first] < number[second]) { post[first] = second; return first; }
		else { post[second] = first; return second; }
	}
	else if (first == post[first]) {
		if (number[first] < number[second]) { post[first] = second; return first; }
		else {
			post[second] = merge(first, post[second]);
			return second;
		}
	}
	else if (second == post[second]) {
		if (number[first] > number[second]) { post[second] = first; return second; }
		else {
			post[first] = merge(post[first], second);
			return first;
		}
	}


	else {
		if (number[first] < number[second]) {
			post[first] = merge(post[first], second);
			return first;
		}
		else {
			post[second] = merge(first, post[second]);
			return second;
		}
	}
}


int sorting(int start, int mount) {
	if (mount == 1) return start;
	else if (mount == 2) {
		if (number[start] < number[start + 1]) {
			post[start] = (start + 1); return start;
		}
		else { post[start + 1] = start; return (start + 1); }
	}
	else {
		int firstindex = sorting(start, mount / 2);
		int secondindex = sorting(start + mount / 2, mount - mount / 2);
		int returnvalue = ((number[firstindex] < number[secondindex]) ? firstindex : secondindex);
		return merge(firstindex, secondindex);
	}
}






int main() {
	string line;
	int counting = 0;

	ifstream file("sorttest1.txt"); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open()) {
		while (getline(file, line)) {
			number[counting++] = stoi(line); // line은 string이기 때문에 int로 바꿀 필요

		}
		file.close(); // 열었던 파일을 닫는다. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	for (int i = 0; i < counting; i++) {
		pre[i] = i;
		post[i] = i;
	}

	int iosnumber = sorting(0, counting); //index of smallest number


	
	while (pre[iosnumber] != post[iosnumber]) {
		cout << iosnumber << '\t' << number[iosnumber] << '\n';
		iosnumber = post[iosnumber];

	}


	

	return 0;
}