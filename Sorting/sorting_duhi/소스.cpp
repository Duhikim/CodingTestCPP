#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int array_size = 60;
//최대값 구하기
int maximum(int array[]) {
	int max = array[0];
	for (int i = 1; i < array_size; i++) {
		max = (array[i] > max) ? array[i] : max;
	}
	return max;
}
//최소값 구하기
int minimum(int array[]) {
	int min = array[0];
	for (int i = 1; i < array_size; i++) {
		min = (array[i] > min) ? array[i] : min;
	}
	return min;
}

//나누기
void dividing(int n, int array[], int max, int min, int count) {
	
	
	if (max==min)
	if (n <= (max + min) / 2) { dividing(n, array, (max + min) / 2, min); }
	else { dividing(n, array, max, max - (max + min) / 2); }
}


int main() {
	string line;
	int numbers[array_size];
	int count = 0;

	ifstream file("sorttest1.txt"); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open()) {
		while (getline(file, line)) {
			numbers[count++] = stoi(line); // line은 string이기 때문에 int로 바꿀 필요

		}
		file.close(); // 열었던 파일을 닫는다. 
	}
	else {
		cout << "Unable to open file";
		return 1;
	}
	int* pIndex;
	pIndex = new int[count];
	for (int i = 0; i < count; i++) { pIndex[i] = i; }


	int* pSorted;
	pSorted = new int[count];


	int max = maximum(numbers);
	int min = minimum(numbers);
	



	delete[] pSorted;
	return 0;
}