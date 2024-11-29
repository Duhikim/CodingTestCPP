#include <iostream>
using namespace std;

int main() {
	
	string word;
	cin >> word;

	int size = word.size();
	//int* pWord;
	//pWord = new int[size];
	int alphabet[26] = { 0 };

	/* //모든 글자 대문자로 변경
	for (int i = 0; i < size; i++) {
		if (word[i] <= 122 && word[i] >= 97) word[i] -= 32;
	}*/

	for (int i = 0; i < size; i++) {
		if (word[i] >= 'a') { alphabet[word[i] - 'a']++; }
		else { alphabet[word[i] - 'A']++; }
	}
		

	int max = alphabet[0];
	int index = 0;
	
	

	for (int i = 1; i < 26; i++) {
		if (alphabet[i] > max) { 
			max = alphabet[i]; 
			index = i; 
		}
		else if (alphabet[i] == max) {	
			index = -1; 
		}
	}
	char ans = (char)(index + 65);
	if (index == -1) cout << "?\n";
	else { cout << ans << '\n'; }

	//소문자의 아스키 코드는 97(a)~122(z), 대문자는 소문자에서 -32 하면 65(A)~90(Z)

	//delete[] pWord;
	return 0;
}