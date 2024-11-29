#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>
#define ll long long

using namespace std;

void Search(string& binary_num, int start, int size, int& ans) {
    if (size == 1 || !ans) return;

    if (binary_num[start + size / 2] == '0') {
        for (int i = start; i < start+size; i++) {
            if (binary_num[i] == '1') {
                ans = 0;
                return;
            }
        }         
        return;
    }
    else if(size>3) {
        Search(binary_num, start + (size / 2) + 1, size / 2, ans);
        Search(binary_num, start, size / 2, ans);                    
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++) {
        ll num = numbers[i];
        
        int n = 0; // num을 2진수로 바꿨을 때 자리수
        while (pow(2,++n) < num) { }
        //n은 1, 3, 5, 7, 15와 같이 2^N-1 형태의 숫자여야 한다. 그보다 작은 경우 앞에 0을 채워서 맞춘다. 채운 자리수를 m이라 함
        int m = 0;
        while (pow(2, ++m)-1 < n) { }
        m = pow(2, m) - 1;        
      
        string binary_num = "";
        for (int i = 0; i < m; i++) {
            binary_num += (num % 2) ? "1" : "0"; // 2진수 스트링이 거꾸로 들어가지만 상관없음
            num /= 2;
        }     
        int ans=1;
        Search(binary_num, 0, m, ans);
        answer[i] = ans;       
    }

    return answer;
}

int main() {
    vector<long long> numbers;
    
    numbers = { 7, 42, 5, 63, 111, 95, 15, 1031, 1031 + 128, 70, 3836, 597, 19880516 };
    cout << "예상 답 : { 1, 1, 0, 1, 1, 0, 1, 0, 0  }, \n계산 값 : { ";
    for (int& num : solution(numbers)) {
        cout << num << "  ";
    }
    cout << "}\n";

   


}