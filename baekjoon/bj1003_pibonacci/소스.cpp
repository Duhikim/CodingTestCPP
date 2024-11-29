#include <iostream>
using namespace std;

int counting0 = 0;
int counting1 = 0;

int fibonacci(int n) {
    
    if (n == 0) {
      
        counting0++;
        return 0;
    }
    else if (n == 1) {
       
        counting1++;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
} 



int main() {

    int size = sizeof(unsigned long long int);
    cout << size << '\n';
    
    int num;
bool loopnumber = 1;
   
while (loopnumber == 1) {

    printf("피보나치 수열(임의의 자연수) \n");
    cin >> num;
    if (num < 0) {
        loopnumber = 0; break;
    }

    unsigned long long int sum = 0;
    unsigned long long int temp1 = 1; //a(n+1)
    unsigned long long int temp2 = 0; //a(n)

    if (num == 0) sum = 0;
    else if (num == 1) sum = 1;
    else {
        for (int i = 2; i <= num; i++) {

            

            sum = temp1 + temp2;

            temp2 = temp1;
            temp1 = sum;


        }
    }
    cout << sum << '\n';
}
    /*
    fibonacci(num);
    
    
    printf("\n%d %d\n", counting0, counting1);
    counting0 = 0;
    counting1 = 0;
}*/

	return 0;
}