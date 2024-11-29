#include <iostream>
using namespace std;

int main() {
	char subject[60], grade[3];
	float score, time, totaltime, sum;
	float scoretime[20];
	
	
	for (int i = 0; i < 20; i++) {
		scanf("%s %f %s", &subject, &time, &grade);

		totaltime += time;
		if (grade[0] == 'A') {
			if (grade[1] == '+') score = 4.5;
			else score = 4.0;
		}
		else if (grade[0] == 'B') {
			if (grade[1] == '+') score = 3.5;
			else score = 3.0;
		}
		else if (grade[0] == 'C') {
			if (grade[1] == '+') score = 2.5;
			else score = 2.0;
		}
		else if (grade[0] == 'D') {
			if (grade[1] == '+') score = 1.5;
			else score = 1.0;
		}
		else if (grade[0] == 'F') { score = 0; }
		else if (grade[0] == 'P') { score = 0; totaltime -= time; }

		scoretime[i] = score * time;
		
	}
	
	for (int i = 0; i < 20; i++) {
		sum += scoretime[i];
	}
	printf("%f", sum / totaltime);

	return 0;
}