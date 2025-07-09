#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	
	int accomodation[367][2];
	for (int i = 0; i < 367; i++) {
		accomodation[i][0] = 0; // T 투숙객 수
		accomodation[i][1] = 0; // S 투숙객 수
	}
	int occDays = 0; // 투숙객이 1명 이상인 날의 수
	int maxGuests = 0; // 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
	int noFightDays = 0; // 싸움이 없는 날의 수
	int maxGuestsNoFight = 0; // 싸움이 없는 날 중 가장 많은 투숙객이 있었던 날에 투숙한 사람의 수
	int longestStay = 0; // 가장 오랜 기간 투숙한 사람이 투숙한 날의 수

	while (N-- > 0) {
		char TS;
		int checkIn, checkOut;
		cin >> TS >> checkIn >> checkOut;

		for (int i = checkIn; i <= checkOut; i++) {
			if (TS == 'T') {
				accomodation[i][0]++;
			}
			else if (TS == 'S') {
				accomodation[i][1]++;
			}
		}
		if (checkOut - checkIn + 1 > longestStay) {
			longestStay = checkOut - checkIn + 1; // 투숙 기간 갱신
		}
	}

	
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] + accomodation[i][1] > 0) {
			occDays++;
		}
		if (accomodation[i][0] + accomodation[i][1] > maxGuests) {
			maxGuests = accomodation[i][0] + accomodation[i][1];
		}
		if (accomodation[i][0] > 0 && accomodation[i][0] == accomodation[i][1]) {
			noFightDays++;
			if ((accomodation[i][0] << 1) > maxGuestsNoFight) {
				maxGuestsNoFight = (accomodation[i][0]<<1);
			}
		}
	} 
	cout << occDays << '\n' << maxGuests << '\n' 
		 << noFightDays << '\n' << maxGuestsNoFight << '\n' 
		<< longestStay << '\n';
	

	return 0;
}