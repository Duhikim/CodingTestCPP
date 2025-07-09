#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	/*
	1. 투숙객이 1명 이상인 날의 수
	2. 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
	3. 싸움이 없는 날의 수
	4. 싸움이 없는 날 중 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수. 싸움이 없는 날이 없으면 0을 출력한다.
	5. 가장 오랜 기간 투숙한 사람이 투숙한 날의 수
	*/
	int accomodation[367][2];
	for (int i = 0; i < 367; i++) {
		accomodation[i][0] = 0; // T 투숙객 수
		accomodation[i][1] = 0; // S 투숙객 수
	}

	int longestStay = 0; // 가장 오랜 기간 투숙한 사람이 투숙한 날의 수

	while (N-- > 0) {
		char TS;
		int checkIn, checkOut;
		cin >> TS >> checkIn >> checkOut;

		for (int i = checkIn; i <= checkOut; i++) {
			if (TS == 'T') {
				accomodation[i][0]++;
			} else if (TS == 'S') {
				accomodation[i][1]++;
			}
		}
		if(checkOut - checkIn + 1 > longestStay) {
			longestStay = checkOut - checkIn + 1; // 투숙 기간 갱신
		}
	}
	int occDays = 0; // 투숙객이 1명 이상인 날의 수
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] + accomodation[i][1] > 0) {
			occDays++;
		}
	} cout << occDays << '\n';

	int maxGuests = 0; // 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] + accomodation[i][1] > maxGuests) {
			maxGuests = accomodation[i][0] + accomodation[i][1];
		}
	} cout << maxGuests << '\n';

	int noFightDays = 0; // 싸움이 없는 날의 수
	vector<int> noFight = {};
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] > 0 && accomodation[i][0] == accomodation[i][1]) {
			noFightDays++;
			noFight.push_back(i);
		}
	} cout << noFightDays << '\n';

	int maxGuestsNoFight = 0; // 싸움이 없는 날 중 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
	for (int day : noFight) {
		if(accomodation[day][0] > maxGuestsNoFight) {
			maxGuestsNoFight = accomodation[day][0];
		}
	} cout << maxGuestsNoFight * 2 << '\n'; // T, S 투숙객 수가 같으므로 2배

	cout << longestStay << '\n'; // 가장 오랜 기간 투숙한 사람이 투숙한 날의 수

	return 0;
}