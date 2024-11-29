#include <iostream>
#include <string>
using namespace std;

class Complex {
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex() : real(0), img(0) {}
	Complex(double real) : real(real), img(0) {}
	Complex(const char* str);
	Complex operator+(const Complex& a) const;
	Complex operator-(const Complex& a) const;
	Complex operator*(const Complex& a) const;
	Complex operator/(const Complex& a) const;
	Complex operator+(const char* str);
	Complex operator-(const char* str);
	Complex operator*(const char* str);
	Complex operator/(const char* str);
	Complex& operator=(const Complex& a);
	bool operator==(const Complex& a) const;
	Complex& operator+=(const Complex& a);
	Complex& operator-=(const Complex& a);
	Complex& operator*=(const Complex& a);
	Complex& operator/=(const Complex& a);

	void println() {
		cout << real;
		if (img > 0) cout << " + " << img << "i" << '\n';
		else if (img == 0) cout << '\n';
		else cout << " - " << -img << "i" << '\n';
	}
};

Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)" ex) -3 + i2
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

	int sz_o_str = strlen(str);
	int pos_o_i = -1;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'i') {
			pos_o_i = i;
			break;
		}
	}
	if (pos_o_i == -1) {
		real = stof(str);
	}
	else {
		string str_temp(str);
		real = stof(str_temp.substr(0, pos_o_i));
		if (str_temp[pos_o_i - 1] == '+' || ((str_temp[pos_o_i - 1] == ' ') && (str_temp[pos_o_i - 2] == '+')))
			img = stof(str_temp.substr(pos_o_i + 1, sz_o_str - pos_o_i - 1));
		if (str_temp[pos_o_i - 1] == '-' || ((str_temp[pos_o_i - 1] == ' ') && (str_temp[pos_o_i - 2] == '-')))
			img = -stof(str_temp.substr(pos_o_i + 1, sz_o_str - pos_o_i - 1));
	}
}

Complex Complex::operator+(const Complex& a)const {
	Complex temp(real + a.real, img + a.img);
	return temp;
}
Complex Complex::operator-(const Complex& a)const {
	Complex temp(real - a.real, img - a.img);
	return temp;
}
Complex Complex::operator*(const Complex& a)const {
	Complex temp(real * a.real - img * a.img, real * a.img + a.real * img);
	return temp;
}
Complex Complex::operator/(const Complex& a) const {
	int div = a.real * a.real + a.img * a.img;
	Complex temp((real * a.real + img * a.img) / div, (-real * a.img + img * a.real) / div);
	return temp;
}
Complex Complex::operator+(const char* str) {
	Complex str_input(str);
	return (*this) + str_input;
}
Complex Complex::operator-(const char* str) {
	Complex str_input(str);
	return (*this) - str_input;
}
Complex Complex::operator*(const char* str) {
	Complex str_input(str);
	return (*this) * str_input;
}
Complex Complex::operator/(const char* str) {
	Complex str_input(str);
	return (*this) / str_input;
}
Complex& Complex::operator=(const Complex& a) {
	real = a.real;
	img = a.img;
	return *this;
}
Complex& Complex::operator+=(const Complex& a) {
	real += a.real;
	img += a.img;
	return *this;
}
Complex& Complex::operator-=(const Complex& a) {
	real -= a.real;
	img - +a.img;
	return *this;
}
Complex& Complex::operator*=(const Complex& a) {
	real = real * a.real - img * a.img;
	img = real * a.img + a.real * img;
	return *this;
}
Complex& Complex::operator/=(const Complex& a) {
	int div = a.real * a.real + a.img * a.img;
	real = (real * a.real + img * a.img) / div;
	img = (-real * a.img + img * a.real) / div;
	return *this;
}
bool Complex::operator==(const Complex& a) const {
	if (real == a.real && img == a.img) return true;
	return false;
}

int main() {
	Complex a(0, 0);
	a = a + "-1.1 + i3.923";
	a.println();
	a = a - "1.2 -i1.823";
	a.println();
	a = a * "2.3+i22";
	a.println();
	a = a / "-12+i55";
	a.println();

	return 0;
}