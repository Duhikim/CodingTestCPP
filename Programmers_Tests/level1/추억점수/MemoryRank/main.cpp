#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> MemPntOf;
    for (int i = 0; i < name.size(); i++) {
        MemPntOf[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); i++) {
        int point = 0;
        for (auto name : photo[i]) {
            point += MemPntOf[name];
        }
        answer.push_back(point);
    }
  
    return answer;
}

int main() {
    vector<string> name1 = { "may", "kein", "kain", "radi" };
    vector<int> yearning1 = { 5, 10, 1, 3 };
    vector<vector<string>> photo1 = {
        {"may", "kein", "kain", "radi"},
        {"may", "kein", "brin", "deny"},
        {"kon", "kain", "may", "coni"}
    };

    for (auto result : solution(name1, yearning1, photo1)) {
        cout << result << " , ";
    } 
    cout << '\n';
    // 기대값 [19, 15, 6]


    vector<string> name2 = { "kali", "mari", "don" };
    vector<int> yearning2 = { 11, 1, 55 };
    vector<vector<string>> photo2 = {
        {"kali", "mari", "don"},
        {"pony", "tom", "teddy"},
        {"con", "mona", "don" }
    };

    for (auto result : solution(name2, yearning2, photo2)) {
        cout << result << " , ";
    } 
    cout << '\n';
    // 기대값 [67, 0, 55]


    vector<string> name3 = { "may", "kein", "kain", "radi" };
    vector<int> yearning3 = { 5, 10, 1, 3 };
    vector<vector<string>> photo3 = { 
        {"may"},
        {"kein", "deny", "may"},
        {"kon", "coni"}
    };

    for (auto result : solution(name3, yearning3, photo3)) {
        cout << result << " , ";
    } 
    cout << '\n';
    // 기대값 [5, 15, 0]


    return 0;
}