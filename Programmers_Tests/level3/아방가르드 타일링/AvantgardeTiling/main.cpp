#include <string>
#include <vector>
#include <iostream>
#define ll long long unsigned

using namespace std;
vector<ll> List(100001);


int solution(int n) {
    int answer = 0;
    if (n == 1) return 1;
    if (n == 2) return 3;    
    if (n == 3) return 10;
    List[0] = 1;
    List[1] = 1;
    List[2] = 3;
    List[3] = 10;
    
    for (int i = 4; i < n+1; i++) {
        if (List[i]) continue;
        int c;
        for (int j = 0; j < i; j++) {
            if (j == 0) c = 1;
            else if ((j + 1) == 3) c = 5;
            else if ((j + 1) % 3 == 0) c = 4;
            else c = 2;
            List[i] += (c * List[i - j - 1]) % 1000000007;
        }
    }
    answer = List[n] % 1000000007;
    return answer;
    // 1,000,000,007로 나눈 나머지를 return
}

int main() {
    int n;
    solution(50);

    for(int i=0; i<20; i++){
        cout << i << " : " << List[i] << '\n';
    }

    //n = 2;
    //cout << "n = " << n << " , " << solution(n) << '\n';

    //n = 3;
    //cout << "n = " << n << " , " << solution(n) << '\n';

    //n = 18;
    //cout << "n = " << n << " , " << solution(n) << '\n';

    //n = 19;
    //cout << "n = " << n << " , " << solution(n) << '\n';

    //n = 20;
    //cout << "n = " << n << " , " << solution(n) << '\n';

    //n = 100000;
    //cout << "n = " << n << " , " << solution(n) << '\n';

}