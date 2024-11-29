#include <iostream>
using namespace std;
/*
문제
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 
이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 
나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.
*/


int N;
struct members_data {
	int age;
	string name;
	};
members_data* member;

int main() {
	cin >> N;
	member = new members_data[N];
	for (int i = 0; i < N; i++) {
		cin >> member[i].age >> member[i].name;
	}
	for (int n = 1; n <= 200; n++) {
		for (int i = 0; i < N; i++) {
			if (member[i].age == n) cout << member[i].age << " " << member[i].name << '\n';
		}
	}
	return 0;
}



/*

int N;
struct members_data {
	int index;
	int age;
	string name;
	int pointer;
};
members_data* member;
 

int merge(int index1, int index2) {
	if ((member[index1].pointer == index1) && (member[index2].pointer == index2)) {
		if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) { member[index1].pointer = index2; return index1; }
		member[index2].pointer = index1; return index2;
	}
	if (member[index1].pointer == index1) {
		if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) { member[index1].pointer = index2; return index1; }
		member[index2].pointer = merge(index1, member[index2].pointer); return index2;
	}
	if (member[index2].pointer == index2) {
		if ((member[index1].age > member[index2].age) || ((member[index1].age == member[index2].age) && (index1 > index2))) { member[index2].pointer = index1; return index2; }
		member[index1].pointer = merge(member[index1].pointer, index2);
	}

	if ((member[index1].age < member[index2].age) || ((member[index1].age == member[index2].age) && (index1 < index2))) {
		member[index1].pointer = merge(member[index1].pointer, index2); return index1;
	}
	member[index2].pointer = merge(index1, member[index2].pointer); return index2;
}

int dividing(int firstindex, int size) {
	if (size == 1) { return firstindex; }
	if (size == 2) {
		if (member[firstindex].age > member[firstindex + 1].age) { member[firstindex + 1].pointer = firstindex; return firstindex + 1; }
		else { member[firstindex].pointer = firstindex + 1; return firstindex; }	//나이가 갖은 경우 firstindex는 항상 firstindex+1보다 먼저 온다.	
	}
	if (size > 2) {
		int one = dividing(firstindex, size / 2);
		int two = dividing(firstindex + size / 2, size - size / 2);
		return merge(one, two);
	}
}

int main() {
	cin >> N;
	member = new members_data[N];
	for (int i = 0; i < N; i++) {
		cin >> member[i].age >> member[i].name;
		member[i].index = i;
		member[i].pointer = i;
	}

	int smallest_member = dividing(0, N);

	while (1) {
		cout << member[smallest_member].age << " " << member[smallest_member].name << '\n';
		if (member[smallest_member].pointer == smallest_member) return 0;
		smallest_member = member[smallest_member].pointer;
	}

}
*/