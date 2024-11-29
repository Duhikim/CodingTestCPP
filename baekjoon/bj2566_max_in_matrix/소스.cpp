#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int matrix[9][9];

	//행렬 배열에 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	//최대값 찾기
	int max = matrix[0][0];
	int indexrow = 0, indexcol = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j] > max) { max = matrix[i][j]; indexrow = i; indexcol = j; }
		}
	}

	printf("%d\n%d %d\n", max, indexrow+1, indexcol+1);

	
	return 0;
	
}