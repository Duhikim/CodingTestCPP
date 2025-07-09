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
		accomodation[i][0] = 0; // T ������ ��
		accomodation[i][1] = 0; // S ������ ��
	}
	int occDays = 0; // �������� 1�� �̻��� ���� ��
	int maxGuests = 0; // ���� ���� �������� �־��� ���� ������ ����� ��
	int noFightDays = 0; // �ο��� ���� ���� ��
	int maxGuestsNoFight = 0; // �ο��� ���� �� �� ���� ���� �������� �־��� ���� ������ ����� ��
	int longestStay = 0; // ���� ���� �Ⱓ ������ ����� ������ ���� ��

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
			longestStay = checkOut - checkIn + 1; // ���� �Ⱓ ����
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