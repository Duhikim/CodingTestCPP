#include <iostream>

using namespace std;

class String {
	char* str;
	int size;
	int capacity;
public:
	String(int capa);
	String(char a);
	String(char a, int b); // 문자로 부터 문자열 생성
	String(const char* char_array); // 문자열로 부터 생성
	String(const String& a);
	~String(); // 소멸자
	int Strlen() { return size; } // 문자열 길이를 구하는 함수
	void Add_string(const String& a); // 문자열 뒤에 다른 문자열 붙이기
	//문자열 내에 포함되어 있는 문자열 구하기 (뭔지 모르겠음)
	bool compare(const String& a);
	void print();
	void println();
	String& assign(const String& a);
	String& assign(const char* a);
	int Capacity() { return capacity; }
	void reserve(int a);
	char at(int i);
	String& insert(int loc, const String& a);
	String& insert(int loc, const char* a);
	String& insert(int loc, char a);
	String& erase(int loc, int num);
	int find(int find_from, String& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, const char a) const;
};

String::String(int capa) {
	capacity = capa;
	str = new char[capacity];
	size = 0;
	cout << "Capacity : " << capacity << '\n';
}
String::String(char a) {
	size = 1;
	capacity = 1;
	str = new char[1];
	str[0] = a;
}
String::String(char a, int b) {
	size = b;
	capacity = size;
	str = new char[b];
	for (int i = 0; i < size; i++) {
		str[i] = a;
	}
}
String::String(const char* char_array) {
	size = strlen(char_array);
	capacity = size;
	str = new char[size];
	for (int i = 0; i < size; i++) {
		str[i] = char_array[i];
	}
}
String::String(const String& a) {
	size = a.size;
	capacity = size;
	str = new char[size];
	for (int i = 0; i < size; i++) {
		str[i] = a.str[i];
	}
}
void String::Add_string(const String& a) {
	int size_temp = size;
	size = size_temp + a.size;

	char* str_temp = new char[size];
	for (int i = 0; i < size_temp; i++) {
		str_temp[i] = str[i];
	}
	delete[] str;
	for (int i = 0; i < a.size; i++) {
		str_temp[size_temp + i] = a.str[i];
	}
	capacity = size;
	str = str_temp;
}
bool String::compare(const String& a) {
	if (size == a.size) {
		for (int i = 0; i < size; i++) {
			if (str[i] != a.str[i]) return 0;
		} return 1;
	}
	return 0;
}
void String::print() {
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
}
void String::println() {
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << '\n';
}
String& String::assign(const String& a) {
	if (capacity < a.size) {
		delete[] str;
		str = new char[a.size];
		capacity = a.size;
	}
	size = a.size;
	for (int i = 0; i < size; i++) {
		str[i] = a.str[i];
	}
	return *this;
}
String& String::assign(const char* a) {
	int size_temp = strlen(a);
	if (capacity < size_temp) {
		delete[] str;
		str = new char[size_temp];
		capacity = size_temp;
	}
	size = size_temp;
	for (int i = 0; i < size; i++) {
		str[i] = a[i];
	}
	return *this;
}
void String::reserve(int a) {
	if (capacity < a) {
		char* str_temp = str;
		str = new char[a];
		capacity = a;
		for (int i = 0; i < size; i++) {
			str[i] = str_temp[i];
		}
		delete[] str_temp;
	}
}
char String::at(int i) {
	if (i >= size || i < 0) {
		cerr << "Fail!" << '\n';
		return NULL;
	}
	else {
		return str[i];
	}
}
String& String::insert(int loc, const String& a) {
	if (loc<0 || loc>size) return *this;
	if (size + a.size > capacity) {
		if (2 * capacity > size + a.size) capacity *= 2;
		else capacity = size + a.size;

		char* str_temp = str; // str_temp는 함수 끝나기 전에 삭제 시켜줘야 함.
		size += a.size;
		str = new char[size];
		for (int i = 0; i < loc; i++) {
			str[i] = str_temp[i];
		}
		for (int i = 0; i < a.size; i++) {
			str[i + loc] = a.str[i];
		}
		for (int i = 0; i < (size - a.size - loc); i++) {
			str[i + loc + a.size] = str_temp[i + loc];
		}
		delete[] str_temp;
		return *this;
	}
	else {
		int newsize = size + a.size;
		for (int i = newsize - 1; i >= loc + a.size; i--) {
			str[i] = str[i - a.size];
		}
		for (int i = 0; i < a.size; i++) {
			str[i + loc] = a.str[i];
		}
		size = newsize;
		return *this;
	}
}
String& String::insert(int loc, const char* a) {
	String temp(a); // 함수 끝나면 자동 소멸
	insert(loc, temp);
	return *this;
}
String& String::insert(int loc, char a) {
	String temp(a); // 함수 끝나면 자동 소멸
	insert(loc, temp);
	return *this;
}
String& String::erase(int loc, int num) {
	if (loc<0 || loc>size) return *this;

	for (int i = 0; i < size - loc - num; i++) {
		str[loc + i] = str[loc + num + i];
	}
	size -= num;
	return *this;
}
int String::find(int find_from, String& str_input) const {
	int j;
	for (int i = find_from; i < size + 1 - str_input.size; i++) {
		for (j = 0; j < str_input.size; j++) {
			if (str[i + j] != str_input.str[j])break;
		}
		if (j == str_input.size) return i;
	}
	return -1;
}
int String::find(int find_from, const char* str_input) const {
	String temp(str_input);
	return find(find_from, temp);
}
int String::find(int find_from, const char a) const {
	String temp(a);
	return find(find_from, temp);
}
String::~String() {
	if (str)delete[] str;
}

int main() {
	String s(3);

	return 0;
}