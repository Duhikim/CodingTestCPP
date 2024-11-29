#include <iostream>
#include <string>
using namespace std;
/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
단, 중복된 단어는 하나만 남기고 제거해야 한다.

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다.
*/

int N;
struct word_data {
	string word;
	int len;
	int index;
	int pre;
	int post;
	bool del = 0;
};
word_data* word_array;


int when_eqlen(word_data word1, word_data word2) {
	
	for (int i = 0; i < word1.len; i++) {
		if (word1.word[i] > word2.word[i]) { if (word_array[word2.index].post == word2.index) { word_array[word2.index].post = word1.index; } return word2.index; }
		if (word1.word[i] < word2.word[i]) { if (word_array[word1.index].post == word1.index) { word_array[word1.index].post = word2.index; } return word1.index; }
	}
	word_array[word2.index].del = 1;
	return word1.index;
}

int merge(int index1, int index2) {
	if (word_array[index1].post == index1 && word_array[index2].post == index2) {
		if (word_array[index1].len < word_array[index2].len) { word_array[index1].post = index2; return index1; }
		if (word_array[index1].len > word_array[index2].len) { word_array[index2].post = index1; return index2; }
		if (word_array[index1].len == word_array[index2].len) { return when_eqlen(word_array[index1], word_array[index2]); }
	}
	
	if (word_array[index1].post == index1) {
		if (word_array[index1].len < word_array[index2].len) { word_array[index1].post = index2; return index1; }
		if (word_array[index1].len > word_array[index2].len) { word_array[index2].post = merge(index1, word_array[index2].post); return index2; }
		if (word_array[index1].len == word_array[index2].len) {
			int temp = when_eqlen(word_array[index1], word_array[index2]);
			if (temp == index1) { 
				if (word_array[index2].del) { word_array[index1].post = word_array[index2].post; }
				return index1;
			}
			else { word_array[index2].post = merge(index1, word_array[index2].post); return index2; }
		}
	}
	if (word_array[index2].post == index2) {
		if (word_array[index2].len < word_array[index1].len) { word_array[index2].post = index1; return index2; }
		if (word_array[index2].len > word_array[index1].len) { word_array[index1].post = merge(index2, word_array[index1].post); return index1; }
		if (word_array[index1].len == word_array[index2].len) {
			int temp = when_eqlen(word_array[index2], word_array[index1]);
			if (temp == index2) {
				if (word_array[index1].del) { word_array[index2].post = word_array[index1].post; }
				return index2;
			}
			else { word_array[index1].post = merge(word_array[index1].post, index2); return index1; }
		}
	}

	if (word_array[index1].len < word_array[index2].len) { word_array[index1].post = merge(word_array[index1].post, index2); return index1; }
	if (word_array[index1].len > word_array[index2].len) { word_array[index2].post = merge(index1, word_array[index2].post); return index2; }
	if (word_array[index1].len == word_array[index2].len) {
		int temp = when_eqlen(word_array[index1], word_array[index2]);
		if (temp == index1) { 
			if (word_array[index2].del) { word_array[index1].post = merge(word_array[index1].post, word_array[index2].post); }
			else { word_array[index1].post = merge(word_array[index1].post, index2); }
			return index1;
		}
		if (temp == index2) { word_array[index2].post = merge(index1, word_array[index2].post); return index2; }
	}
}

int dividing(int firstindex ,int size) {
	if (size == 1) { return firstindex; }
	if (size == 2) {
		if (word_array[firstindex].len < word_array[firstindex + 1].len) { word_array[firstindex].post = word_array[firstindex + 1].index; return firstindex; }
		if (word_array[firstindex].len > word_array[firstindex + 1].len) { word_array[firstindex + 1].post = word_array[firstindex].index; return firstindex + 1; }
		if (word_array[firstindex].len == word_array[firstindex + 1].len) { return when_eqlen(word_array[firstindex], word_array[firstindex + 1]); }
	}
	if (size > 2) {
		int one = dividing(firstindex, size / 2);
		int two = dividing(firstindex + size / 2, size - size / 2);
		return merge(one, two);
	}
}

int main() {
	cin >> N;
	word_array = new word_data[N];

	for (int i = 0; i < N; i++) {
		cin >> word_array[i].word;
		word_array[i].len = word_array[i].word.length();
		word_array[i].index = i;
		word_array[i].pre = i;
		word_array[i].post = i;
	}
	
	int smallest_word = dividing(0, N);

	while (1) {
		if (!word_array[smallest_word].del) cout << word_array[smallest_word].word << '\n';
		if (word_array[smallest_word].post == smallest_word) return 0;
		smallest_word = word_array[smallest_word].post;
	}

}