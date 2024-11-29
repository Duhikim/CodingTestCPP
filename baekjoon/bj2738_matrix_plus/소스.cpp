#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int** matA;
	matA = new int* [N];
	int** matB;
	matB = new int* [N];

	for (int i = 0; i < N; i++) {
		matA[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &matA[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		matB[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &matB[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j < M - 1) { printf("%d ", matA[i][j] + matB[i][j]); }
			else { printf("%d\n", matA[i][j] + matB[i][j]); }
		}
	}
	
	//메모리 해제
	for (int i = 0; i < N; i++) {
		delete[] matA[i];
		delete[] matB[i];
	}
	delete[] matA;
	delete[] matB;

	return 0;
}