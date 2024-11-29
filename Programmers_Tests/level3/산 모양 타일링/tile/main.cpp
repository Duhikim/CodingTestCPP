#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    // tops의 첫째 항부터 봄. 1일경우 4, 0일경우 3.  이것을 a1이라 하자.
    // 둘째 항을 봄. 1일 경우, 4*a1 - 1. 0일 경우 3*a1 - 1. 이것을 a2.
    // 셋째 항을 봄. 1일 경우 4*a2 - a1, 0일 경우 3* a2- a1. 이것을 a3.
    // 피보나치와 비슷함. n번째 항을 a(n)이라 할 경우, n번째 tops가 1일 경우 4*a(n-1) - a(n-2), 0일 경우 3*a(n-1) - a(n-2)로 하면 된다.
    unsigned long long num_of_cases;   
    unsigned long long temp1, temp2=1; // 각자 a(n-1), a(n-2)를 저장할 예정.
            
    if (tops[0]) num_of_cases = 4;
    else num_of_cases = 3;
    if (n == 1) return num_of_cases;
    temp1 = num_of_cases;

    for (int i = 1; i < n; i++) {
        if (tops[i]) {
            num_of_cases = 4 * temp1 - temp2;
            temp2 = temp1%10007;
            temp1 = num_of_cases%10007;
        }
        else {
            num_of_cases = 3 * temp1 - temp2;
            temp2 = temp1%10007;
            temp1 = num_of_cases%10007;
        }
        if (((4 * temp1) < temp2 ) || ((3 * temp1) < temp2 ) ) {
            temp1 += 10007;
        }        
    }

    answer = num_of_cases % 10007;
    return answer;
}


int main() {
    int n;
    vector<int> tops;
    
    n = 4;
    tops = { 1,1,0,1 };
    cout << "예상 149, 답 : " << solution(n, tops) << '\n';

    n = 2;
    tops = { 0,1 };
    cout << "예상 11, 답 : " << solution(n, tops) << '\n';

    n = 10;
    tops = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    cout << "예상 7704, 답 : " << solution(n, tops) << '\n';

    cout << "\n여기서 부터는 사이즈 테스트 용입니다.\n";
    n = 100000;
    cout << "크기: " << n << '\n';
    tops.clear();
    for (int i = 0; i < n; i++) {
        tops.push_back(1);
    }
    cout << solution(n, tops) << '\n';
   
       
    
    return 0;
}