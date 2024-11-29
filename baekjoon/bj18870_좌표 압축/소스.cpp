#include <iostream>
using namespace std;

bool debug = //true;
			false;

struct Coord {
	int index;
	int coord;
	int pPost;	
	int compressed;
};
int N;
Coord* coord;

int merge(int index1, int index2) {
	if (coord[index1].pPost == index1 && coord[index2].pPost == index2) {
		if (coord[index1].coord <= coord[index2].coord) {
			coord[index1].pPost = index2; 		
			return index1;
		}		
		coord[index2].pPost = index1; 		
		return index2;
	}
	if (coord[index1].pPost == index1) {
		if (coord[index1].coord <= coord[index2].coord) { 
			coord[index1].pPost = index2; 			
			return index1; }
		coord[index2].pPost = merge(index1, coord[index2].pPost); return index2;
	}
	if (coord[index2].pPost == index2) {
		if (coord[index2].coord < coord[index1].coord) {
			coord[index2].pPost = index1; return index2;
		}
		if (coord[index1].coord == coord[index2].coord) {			
		coord[index2].pPost = coord[index1].pPost; coord[index1].pPost = index2; return index1; }
		coord[index1].pPost = merge(coord[index1].pPost, index2); return index1;
	}

	if (coord[index1].coord < coord[index2].coord) { coord[index1].pPost = merge(coord[index1].pPost, index2); return index1; }
	if (coord[index1].coord == coord[index2].coord) {
		coord[index2].pPost = merge(coord[index1].pPost, coord[index2].pPost); coord[index1].pPost = index2; return index1; }
	coord[index2].pPost = merge(index1, coord[index2].pPost); return index2;
}

int dividing(int start, int size) {
	if (size == 1) { return start; }
	if (size == 2) {
		if (coord[start].coord <= coord[start + 1].coord) { 
			coord[start].pPost = start + 1; 			
			return start; }	
	coord[start + 1].pPost = start; 	
	return start + 1;
	}
	if (size > 2) {
		int index1 = dividing(start, size / 2);
		int index2 = dividing(start + size / 2, size - size / 2);
		return merge(index1, index2);
	}
}

int main() {	
	do {		
		cin >> N;
		coord = new Coord[N];

		for (int i = 0; i < N; i++) {
			cin >> coord[i].coord;
			coord[i].index = i;
			coord[i].pPost = i;
			
		}

		int first_coord = dividing(0, N);
		int sum = -1;
		int temp;
		for (int i = 0; i < N; i++) {
			if (sum < 0) { coord[first_coord].compressed = ++sum; temp = coord[first_coord].coord;	}
			else if (temp != coord[first_coord].coord) { coord[first_coord].compressed = ++sum; temp = coord[first_coord].coord;}
			else { coord[first_coord].compressed = sum; }
			
			if (debug) {
				cout << "index : " << first_coord << "  coord : " << coord[first_coord].coord << "  compressed : " << coord[first_coord].compressed << '\n';
			}
			first_coord = coord[first_coord].pPost;
		}


		if (debug) {
			for (int i = 0; i < N; i++) {
				cout << "index: " << i << "  coord:" << coord[i].coord << "  post: " << coord[i].pPost << " compressed: " << coord[i].compressed <<'\n';
			}
		}

		for (int i = 0; i < N; i++) {
			cout << coord[i].compressed << " ";
		}
		cout << '\n';		
	} while (debug);
	return 0;
}
