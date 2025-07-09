#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	/*
	1. �������� 1�� �̻��� ���� ��
	2. ���� ���� �������� �־��� ���� ������ ����� ��
	3. �ο��� ���� ���� ��
	4. �ο��� ���� �� �� ���� ���� �������� �־��� ���� ������ ����� ��. �ο��� ���� ���� ������ 0�� ����Ѵ�.
	5. ���� ���� �Ⱓ ������ ����� ������ ���� ��
	*/
	int accomodation[367][2];
	for (int i = 0; i < 367; i++) {
		accomodation[i][0] = 0; // T ������ ��
		accomodation[i][1] = 0; // S ������ ��
	}

	int longestStay = 0; // ���� ���� �Ⱓ ������ ����� ������ ���� ��

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
			longestStay = checkOut - checkIn + 1; // ���� �Ⱓ ����
		}
	}
	int occDays = 0; // �������� 1�� �̻��� ���� ��
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] + accomodation[i][1] > 0) {
			occDays++;
		}
	} cout << occDays << '\n';

	int maxGuests = 0; // ���� ���� �������� �־��� ���� ������ ����� ��
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] + accomodation[i][1] > maxGuests) {
			maxGuests = accomodation[i][0] + accomodation[i][1];
		}
	} cout << maxGuests << '\n';

	int noFightDays = 0; // �ο��� ���� ���� ��
	vector<int> noFight = {};
	for (int i = 1; i <= 366; i++) {
		if (accomodation[i][0] > 0 && accomodation[i][0] == accomodation[i][1]) {
			noFightDays++;
			noFight.push_back(i);
		}
	} cout << noFightDays << '\n';

	int maxGuestsNoFight = 0; // �ο��� ���� �� �� ���� ���� �������� �־��� ���� ������ ����� ��
	for (int day : noFight) {
		if(accomodation[day][0] > maxGuestsNoFight) {
			maxGuestsNoFight = accomodation[day][0];
		}
	} cout << maxGuestsNoFight * 2 << '\n'; // T, S ������ ���� �����Ƿ� 2��

	cout << longestStay << '\n'; // ���� ���� �Ⱓ ������ ����� ������ ���� ��

	return 0;
}