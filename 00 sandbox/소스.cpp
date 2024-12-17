#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

class MyClass {
public:
    int faceNum;
    int innerNum;

    MyClass(int i) {
        faceNum = i;
        innerNum = 5 - i;
    }
};

bool compare(MyClass A, MyClass B) {
    int a = A.faceNum, b = B.faceNum;
    cout << std::boolalpha << "[ a : " << a << " , b : " << b << " , a <= b : " << (bool)(a <= b) << " ]" << '\n';
    return a < b;
}

int main() {
   
    vector<MyClass> aVec;

    MyClass temp1(3);
    aVec.push_back(temp1);
    MyClass temp2(2);
    aVec.push_back(temp2);
    MyClass temp3(5);
    aVec.push_back(temp3);
    MyClass temp4(1);
    aVec.push_back(temp4);
    MyClass temp5(4);
    aVec.push_back(temp5);
    MyClass temp6(6);
    temp6.faceNum = 3;    
    aVec.push_back(temp6);

    cout << "Before Sort\n";
    for (int i = 0; i < 6; i++) {
        cout << aVec[i].faceNum << " , ";
    }cout << '\n';
    for (int i = 0; i < 6; i++) {
        cout << aVec[i].innerNum << " , ";
    }cout << '\n';
    
    sort(aVec.begin(), aVec.end(), compare);


    cout << "After Sort\n";
    for (int i = 0; i < 6; i++) {
        cout << aVec[i].faceNum << " , ";
    }cout << '\n';
    for (int i = 0; i < 6; i++) {
        cout << aVec[i].innerNum << " , ";
    }cout << '\n';
    
    return 0;
}