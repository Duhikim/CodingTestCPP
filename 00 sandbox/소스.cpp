#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> test = { 1,2,3,4,5,6,7,8,9 }; // 이 데이터는 지워지지 않음이 보장된다.

    deque<int&> refVector = {};
    refVector.push_back(test[8]);
    cout << "참조 벡터에 어떤 값을 저장하였다. (참조) refVector[0] = " << refVector[0] << '\n';
    test[8] = 19;
    cout << "원본 데이터의 값을 9에서 19로 변경하였다. refVector[0] = " << refVector[0] << '\n';
    int& a = refVector.back();
    cout << "int& a는 refVector의 값(참조값)을 참조한다." << '\n';
    int b = refVector.back();
    cout << "int b는 refVector의 값(참조값)을 복사한다." << '\n';
    return 0;
}