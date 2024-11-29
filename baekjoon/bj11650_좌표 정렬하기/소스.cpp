#include <iostream>
using namespace std;
bool debug = //true;
			false;

/*
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다
예제 입력
5
3 4
1 1
1 -1
2 2
3 3
예제 출력
1 -1
1 1
2 2
3 3
3 4
*/

struct coord {
	int index;
	int xcoord;
	int ycoord;
	int pre;
	int post;
};
int N;
coord* Coord;

int merge(int fst, int scd) {
	if ((Coord[fst].post == Coord[fst].index) && (Coord[scd].post == Coord[scd].index)) {
		if ((Coord[fst].xcoord > Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord > Coord[scd].ycoord))) { Coord[scd].post = Coord[fst].index; 	return scd; }
		else { Coord[fst].post = Coord[scd].index; return fst; }
	}

	if (Coord[fst].post == Coord[fst].index) {
		if ((Coord[fst].xcoord < Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord <= Coord[scd].ycoord))) { Coord[fst].post = Coord[scd].index; return fst; }
		else { Coord[scd].post = merge(fst, Coord[scd].post); return scd; }
	}

	if (Coord[scd].post == Coord[scd].index) {
		if ((Coord[fst].xcoord > Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord > Coord[scd].ycoord))) { Coord[scd].post = Coord[fst].index; return scd; }
		else { Coord[fst].post = merge(Coord[fst].post, scd); return fst; }
	}

	if ((Coord[fst].xcoord < Coord[scd].xcoord) || ((Coord[fst].xcoord == Coord[scd].xcoord) && (Coord[fst].ycoord < Coord[scd].ycoord))) { Coord[fst].post = merge(Coord[fst].post, scd); return fst; }
	else { Coord[scd].post = merge(fst, Coord[scd].post); return scd; }


}

int slapchop(coord top, int size) {
	if (size == 1) return top.index;
	if (size == 2) {
		if ((top.xcoord > Coord[top.index + 1].xcoord)||((top.xcoord==Coord[top.index+1].xcoord) && (top.ycoord > Coord[top.index + 1].ycoord))) {
			Coord[top.index + 1].post = top.index; 
			if (debug) { cout << "index: " << top.index + 1 << "  xcoord: " << Coord[top.index+1].xcoord << "  ycoord: " << Coord[top.index + 1].ycoord << "   next index: " << Coord[top.index + 1].post << '\n'; }
			return (top.index + 1);
		}
		else {
			Coord[top.index].post = Coord[top.index+1].index; 
			if (debug) { cout << "index: " << top.index << "  xcoord: " << top.xcoord << "  ycoord: " << top.ycoord << "   next index: " << top.post << '\n'; }
			return (top.index);
		}
	}
	if (size > 2) {
		int first = slapchop(top, size / 2);
		int second = slapchop(Coord[top.index+(size / 2)], size - size / 2);
		return merge(first, second);
	}
}


int main() {
	
	cin >> N;
	Coord = new coord[N];
	
	for (int i = 0; i < N; i++) {
		cin >> Coord[i].xcoord >> Coord[i].ycoord;
		Coord[i].index = i;
		Coord[i].pre = i;
		Coord[i].post = i;
	}
	
	int smallest_index = slapchop(Coord[0], N);

	if (debug) {
		cout << "(디버그)" << '\n' << "index / xcoord / ycoord / pre / post\n";
		for (int i = 0; i < N; i++) {
			cout << Coord[i].index << "     /   " << Coord[i].xcoord << "   /   " << Coord[i].ycoord << "     /  " << Coord[i].pre << " /   " << Coord[i].post << '\n';
		}
		cout << "(디버그 끝)" << '\n';

	}

	while (1) {
		cout << Coord[smallest_index].xcoord << " " << Coord[smallest_index].ycoord << '\n';
		if (smallest_index == Coord[smallest_index].post) break;
		smallest_index = Coord[smallest_index].post;
	}
	

	delete[] Coord;
	return 0;
}