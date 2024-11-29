#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    enum Metrics {
        Give = 0,
        Take = 1,
        Index = 2,
        Expect = 3
    };

    int** give_take = new int* [friends.size()];
    int* give_take_index[4];

    for (int i = 0; i < friends.size(); i++) {
        give_take[i] = new int[friends.size()];
    }
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            give_take[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        give_take_index[i] = new int[friends.size()];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < friends.size(); j++) {
            give_take_index[i][j] = 0;
        }
    }
    // 할당 끝

    // gift 입력 데이터를 give_take 배열에 배치
    for (int i = 0; i < gifts.size(); i++)
    {
        string giver_name = {};
        int giver_num = -1;
        int giver_len = 0;
        int dvpoint = 0;

        for (int j = 0; gifts[i][j] != (const char)' '; j++)
        {
            giver_name += gifts[i][j];
            giver_len = j + 1;
        }

        string taker_name = {};
        int taker_num = -1;
        int taker_len = 0;

        dvpoint = giver_len + 1;

        for (int j = dvpoint; gifts[i][j]; j++)
        {
            taker_name += gifts[i][j];
            taker_len++;
        }


        for (int j = 0; j < friends.size(); j++)
        {
            for (int k = 0; friends[j][k] == giver_name[k]; k++)
            {
                if (k == giver_len) {
                    giver_num = j;
                    break;
                }
            }
            if (giver_num >= 0) break;
        }

        for (int j = 0; j < friends.size(); j++)
        {
            for (int k = 0; friends[j][k] == taker_name[k]; k++)
            {
                if (k == taker_len) {
                    taker_num = j;
                    break;
                }
            }
            if (taker_num >= 0) break;
        }
        give_take[giver_num][taker_num]++;
    }
    ////
    int count_num = 0;

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = 0; j < friends.size(); j++) {
            if (i != j)count_num += give_take[i][j];
        }
        give_take_index[Give][i] = count_num;
        count_num = 0;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = 0; j < friends.size(); j++) {
            if (i != j)count_num += give_take[j][i];
        }
        give_take_index[Take][i] = count_num;
        count_num = 0;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        give_take_index[Index][i] = give_take_index[Give][i] - give_take_index[Take][i];
    }

    //배치 끝

    //분석
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            if (give_take[i][j] > give_take[j][i]) {
                give_take_index[Expect][i]++;
            }
            else if (give_take[i][j] < give_take[j][i]) {
                give_take_index[Expect][j]++;
            }
            else {
                if (give_take_index[Index][i] > give_take_index[Index][j]) { give_take_index[Expect][i]++; }
                else if (give_take_index[Index][i] < give_take_index[Index][j]) { give_take_index[Expect][j]++; }
            }
        }
    }

    for (int i = 0; i < friends.size(); i++) {
        if (give_take_index[Expect][i] > answer) answer = give_take_index[Expect][i];
    }


    //동적 할당 해제
    for (int i = 0; i < 3; i++)
    {
        delete[] give_take_index[i];
    }
    for (int i = 0; i < friends.size(); i++) {
        delete[] give_take[i];
    }
    return answer;


}


int main() {

    vector<string> friends1 = { 
        "muzi", "ryan", "frodo", "neo" };
    vector<string> gifts1 = { 
        "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", 
        "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

    int result1 = solution(friends1, gifts1);

    cout << result1 << '\n';

    vector<string> friends2 = { 
        "joy", "brad", "alessandro", "conan", "david" };
    vector<string> gifts2 = { 
        "alessandro brad", "alessandro joy", "alessandro conan", 
        "david alessandro", "alessandro david" };

    int result2 = solution(friends2, gifts2);

    cout << result2 << '\n';

    vector<string> friends3 = { 
        "a", "b", "c" };
    vector<string> gifts3 = { 
        "a b", "b a", "c a", 
        "a c", "a c", "c a" };

    int result3 = solution(friends3, gifts3);

    cout << result3 << '\n';

    return 0;
}
