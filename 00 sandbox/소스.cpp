#include <iostream>
using namespace std;

int main() {
    

    int num = 7;
    int* p = &num;
    int** pp = &p;

    cout << *pp << '\n' << p << '\n' << &num << '\n';
    
    return 0;
}
