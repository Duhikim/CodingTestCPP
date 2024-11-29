#include <iostream>

using namespace std;


int main() {
	bool debug = true;
				//false;
	do  {
		int N;		
		cin >> N;
		int answer[10] = { 0, };

		int a, b, c, d, e, f, g;
		for (int i = 9; i >= 0; i--) {
			if (i * 1000001 < N) {
				a = i;
				for (int j = 9; j >= 0; j--) {
					if (i * 1000001 + j * 100001 < N) {
						b = j;
						for (int k = 9; k >= 0; k--) {
							if (i * 1000001 + j * 100001 + k * 10001 < N) {
								c = k;
								for (int l = 9; l >= 0; l--) {
									if (i * 1000001 + j * 100001 + k * 10001 + l * 1001 < N) {
										d = l;
										for (int m = 9; m >= 0; m--) {
											if (i * 1000001 + j * 100001 + k * 10001 + l * 1001 + m * 101 < N) {
												e = m;
												for (int n = 9; n >= 0; n--) {
													if (i * 1000001 + j * 100001 + k * 10001 + l * 1001 + m * 101 + n * 11 < N) {
														f = n;
														for (int o = 9; o >= 0; o--) {
															if (i * 1000001 + j * 100001 + k * 10001 + l * 1001 + m * 101 + n * 11 + o * 2 == N) {
																g = o;
																for (int p = 0; p < 10; p++) {
																	if (!answer[p]) {
																		answer[p] = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + e * 100 + f * 10 + g; break;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (debug) { for (int i = 0; i < 10; i++) cout << answer[i] << " "; cout << '\n'; }
		if (!debug) {
			int min = answer[0];
			for (int i = 1; i < 10; i++) {
				if (answer[i] && answer[i] < min) min = answer[i];
			}
			cout << min << '\n';
		}

	} while (debug);
		return 0;
	}