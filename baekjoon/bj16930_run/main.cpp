#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
class Point {
public:
	int x;
	int y;
	bool visitedFromFront;
	bool visitedFromBack;
	int cost;
	bool isWay;
	
	Point() {}
	Point(int x, int y) 
		: x(x), y(y), visitedFromFront(false), visitedFromBack(false), cost(-1), isWay(true) {}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {
	int N, M, K;

	cin >> N >> M >> K;
	vector<vector<Point>> Matrix(N, vector<Point>(M));
	for (int i = 0; i < N; i++) {
		string makeMap;
		cin >> makeMap;
		for (int j = 0; j < M; j++) {
			Point point(i, j);
			Matrix[i][j] = point;
			Matrix[i][j].isWay = (makeMap[j] == '#')? false: true;			
		}
	}
	int sX, sY, eX, eY;
	cin >> sX >> sY >> eX >> eY;
	sX--; sY--; eX--; eY--;

	int cost = 0;
	Matrix[sX][sY].cost = 0;
	Matrix[eX][eY].cost = 0;

	list<Point*> curFromFront, nextFromFront, curFromBack, nextFromBack;
	nextFromFront.push_back(&Matrix[sX][sY]);
	nextFromBack.push_back(&Matrix[eX][eY]);

	do{
		curFromFront.swap(nextFromFront);
		curFromBack.swap(nextFromBack);

		cost++;

		while (curFromFront.size()) {
			int tempX = curFromFront.front()->x;
			int tempY = curFromFront.front()->y;
			curFromFront.pop_front();			

			for (int dir = 0; dir < 4; dir++) {
				for (int i = 1; i <= K; i++) {
					int x = tempX + dx[dir] * i;
					int y = tempY + dy[dir] * i;
					if (x < 0 || y < 0 || x >= N || y >= M || !Matrix[x][y].isWay) break;
					if (Matrix[x][y].visitedFromFront) continue;
					if (Matrix[x][y].visitedFromBack) {
						cout << Matrix[x][y].cost + cost << '\n';
						return 0;
					}
					Matrix[x][y].cost = cost;
					Matrix[x][y].visitedFromFront = true;
					nextFromFront.push_back(&Matrix[x][y]);
				}
			}
		}
		while (curFromBack.size()) {
			int tempX = curFromBack.front()->x;
			int tempY = curFromBack.front()->y;
			curFromBack.pop_front();

			for (int dir = 0; dir < 4; dir++) {
				for (int i = 1; i <= K; i++) {
					int x = tempX + dx[dir] * i;
					int y = tempY + dy[dir] * i;
					if (x < 0 || y < 0 || x >= N || y >= M || !Matrix[x][y].isWay) break;
					if (Matrix[x][y].visitedFromBack) continue;
					if (Matrix[x][y].visitedFromFront) {
						cout << Matrix[x][y].cost + cost << '\n';
						return 0;
					}
					Matrix[x][y].cost = cost;
					Matrix[x][y].visitedFromBack = true;
					nextFromBack.push_back(&Matrix[x][y]);
				}
			}
		}

	} while (nextFromFront.size() && nextFromBack.size());

	cout << -1 << '\n';
	return 0;

}
