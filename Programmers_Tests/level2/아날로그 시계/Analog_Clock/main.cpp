#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool debug = //true;
            false;

int bnbn(int h1, int m1, int s1, int h2, int m2, int s2);
int bnan(int h1, int m1, int s1, int h2, int m2, int s2);

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;
    // 1. 오전~오전일 경우 (or 오후~오후 일 경우. 이경우는 12시간씩 뺀 후 오전~오전과 똑같이 계산하면 된다.)
    if (debug) {
        printf("시작 시간 : %d 시 %d 분 %d 초\n", h1, m1, s1); 
        printf("끝난 시간 : %d 시 %d 분 %d 초\n\n", h2, m2, s2);
    }
    
    if (h1 < 12 && h2 < 12) {
        answer = bnbn(h1, m1, s1, h2, m2, s2);
    }
    else if (h1 >= 12 && h2 >= 12) {
        answer = bnbn(h1-12, m1, s1, h2-12, m2, s2);
    }
    
    // 2. 오전~오후 일 경우. (12시 정각에서 시/분/초침이 한 번에 만남)
    else {
        answer = bnan(h1, m1, s1, h2, m2, s2);
    }  
  
    return answer;
}

int bnbn(int h1, int m1, int s1, int h2, int m2, int s2) {
    int counter = 0;
    
    
    float h_start = (float)h1 + ((float)m1 / 60) + ((float)s1 / 3600);
    float h_end = (float)h2 + ((float)m2 / 60) + ((float)s2 / 3600);
    if (debug) {
        cout << "시작 시간 : " << h_start << "(시)" <<'\n';
        cout << "끝 시간 : " << h_end << "(시)" << '\n';
    }
    
    // 시침, 분침
    int a = -1, b = -1;
   /* for (float i = 0; i < 11; i++) {
        if (a == -1) {
            if (h_start == (12  * (float)i) / 11) {
                counter++;
                if (debug) cout << (12 * i) / 11 <<" (시)에 시침과 분침이 만남 (+1)\n";
                a = i;
            }
            else if (((12  * (float)i) / 11) < h_start && h_start < ((12  * (float)(i + 1)) / 11)) {
                a = i;
            }
        }
        if (a!=-1) {
            if (((12  * (float)i) / 11) <= h_end && h_end < ((12  * (float)(i + 1))/ 11)) {
                b = i;
                break;
            }
        }
    }
    if (debug) {
        cout << "시침 / 분침" << '\n';
        cout << "시작 시점의 index : " << a << '\n';
        cout << "끝 시점의 index : " << b << '\n';
        cout << "시침과 분침은 " << b - a << " 번 더 만난다. \n";
    }
    counter += (b - a);*/

    // 시침, 초침
    a = -1; b = -1;
    for (float i = 0; i < 719; i++) {
        if (a == -1) {
            if (h_start == (12 * i) / 719) {
                counter++;
                if (debug) cout << (12 * i) / 719 << " (시)에 시침과 초침이 만남 (+1)\n";
                a = i;
            }
            else if (((12 * i) / 719) < h_start && h_start < ((12 * (i + 1)) / 719)) {
                a = i;
            }
        }
        if (a != -1) {
            if (((float)(12  * i) / 719) <= h_end && h_end < ((float)(12 * (i + 1)) / 719)) {
                b = i;
                break;
            }
        }
    }
    if (debug) {
        cout << "시침 / 초침" << '\n';
        cout << "시작 시점의 index : " << a << '\n';
        cout << "끝 시점의 index : " << b << '\n';
        cout << "시침과 초침은 " << b - a << " 번 더 만난다. \n\n";
    }
    counter += (b - a);


    // 분침, 초침
    float m_start = (float)m1 + (float)s1 / 60;
    float m_end = (float)m2 + (float)s2 / 60;
    if (debug) {
        cout << "시작 분 : " << m_start << "(분)" <<'\n';
        cout << "끝 분 : " << m_end << "(분)" << '\n';
    }
    a = -1; b = -1;
    if (h1 == h2) {
        for (float i = 0; i < 59; i++) {
            if (a == -1) {
                if (m_start == (60 * i) / 59) {
                    counter++;
                    if (debug) cout << (60 * i) / 59<< " 분에 분침과 초침이 만남 (+1)\n";
                    a = i;
                }
                else if (((60 * i) / 59) < m_start && m_start < ((60 * (i + 1)) / 59)) {
                    if (debug) cout << (60 * i) / 59 << " 분 과 " << (60 * (i + 1)) / 59 << " 분 사이에서 시작함. \n";
                    a = i;
                }
            }
            if (a != -1) {
                if (((60 * i) / 59) <= m_end && m_end < ((60 * (i + 1)) / 59))
                {
                    if (debug) cout << (60 * i) / 59 << " 분 과 " << (60 * (i + 1)) / 59 << " 분 사이에서 끝남. \n";
                    b = i;
                    break;
                }
            }
        }
        counter += (b - a);
        if (debug) {
            cout << "분침 / 초침" << '\n';
            cout << "분침과 초침은 " << b-a << " 번 더 만난다. \n\n";
        }
    }
    else {
        counter += (h2 - h1 - 1) * 59;
        if (debug) cout << "한시간에 59번씩 " << h1 + 1 << "시 부터 " << h2 << " 시 전 까지 초침과 분침이 " << (h2 - h1 - 1) * 59 << " 번 만난다. \n";
        for (float i = 0; i < 59; i++) {
            if (a == -1) {
                if (m_start == 0) {
                    a = 59;
                }
                else if ( ((60*i)/59) <= m_start && m_start < ((60 * (i+1)) / 59)) {
                    a = 58-i;
                }
            }           
            if (b == -1) {
                if (m_end == 0) {
                    b = 1;
                }
                else if (((60 * i) / 59) <= m_end && m_end < ((60 * (i + 1)) / 59)) {
                    b = i+1;
                }
            }             
            if (a != -1 && b != -1) {
                if (debug) {
                    printf("%d시 %d분 %d초 부터 %d시 이전 까지 분침과 초침은 %d 번 만난다.\n", h1, m1, s1, h1 + 1, a);
                    printf("%d시 부터 %d시 %d분 %d초 까지 분침과 초침은 %d 번 만난다.\n", h2, h2, m2, s2, b);
                }
                break;
            }
        }
        counter += (a + b);
        if (debug) {
            cout << "분침 / 초침" << '\n';            
            cout << "분침과 초침은 " << a+b << " 번 더 만난다. \n\n";
        }
    }

    if (!h1 && !m1 && !s1) {
        counter -= 1; 
        if (debug) cout << "0시 0분 0초에 시작하여 -1 처리 함 \n";
    }
    if (debug) cout << '\n';
    return counter;
}

int bnan(int h1, int m1, int s1, int h2, int m2, int s2) {
        
    int bn = bnbn(h1, m1, s1, 11, 59, 59);
    int an = bnbn(0, 0, 0, h2-12, m2, s2);

    return (bn + an);
}


int main() {
    int h1_1 = 0, m1_1 = 5, s1_1 = 30;
    int h2_1 = 0, m2_1 = 7, s2_1 = 0;
    cout << "1번문제, 예상 답안 2" << '\n';
    cout << solution(h1_1, m1_1, s1_1, h2_1, m2_1, s2_1) << "\n\n\n";
    

    int h1_2=12, m1_2=0, s1_2=0;
    int h2_2=12, m2_2=0, s2_2=30;
    cout << "2번문제, 예상 답안 1" << '\n';
    cout << solution(h1_2, m1_2, s1_2, h2_2, m2_2, s2_2) << "\n\n\n";

    int h1_3=0, m1_3=6, s1_3=1;
    int h2_3=0, m2_3=6, s2_3=6;
    cout << "3번문제, 예상 답안 0" << '\n';
    cout << solution(h1_3, m1_3, s1_3, h2_3, m2_3, s2_3) << "\n\n\n";

    int h1_4 = 11, m1_4 = 59, s1_4 = 30;
    int h2_4 = 12, m2_4 = 0, s2_4 = 0;
    cout << "4번문제, 예상 답안 1" << '\n';
    cout << solution(h1_4, m1_4, s1_4, h2_4, m2_4, s2_4) << "\n\n\n";

    int h1_5=11, m1_5=58, s1_5=59;
    int h2_5=11, m2_5=59, s2_5=0;
    cout << "5번문제, 예상 답안 1" << '\n';
    cout << solution(h1_5, m1_5, s1_5, h2_5, m2_5, s2_5) << "\n\n\n";

    int h1_6=1, m1_6=5, s1_6=5;
    int h2_6=1, m2_6=5, s2_6=6;
    cout << "6번문제, 예상 답안 2" << '\n';
    cout << solution(h1_6, m1_6, s1_6, h2_6, m2_6, s2_6) << "\n\n\n";

    int h1_7=0, m1_7=0, s1_7=0;
    int h2_7=23, m2_7=59, s2_7=59;
    cout << "7번문제, 예상 답안 2852" << '\n';
    cout << solution(h1_7, m1_7, s1_7, h2_7, m2_7, s2_7) << "\n\n\n";

}