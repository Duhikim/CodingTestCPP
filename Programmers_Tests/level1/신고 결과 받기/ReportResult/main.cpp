#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;    
   
    set<string> report_set;
    vector<vector<string>> report_unq;

    for (string log : report) {
        report_set.insert(log);
    }

    for (string log : report_set) {
        std::istringstream iss(log); // 문자열 스트림 생성        
        std::string word;
        vector<string> temp;
        while (iss >> word) {
            temp.push_back(word); // 단어를 벡터에 추가
        }
        report_unq.push_back(temp);
    }

    map<string, int> idMap;
    for (string id : id_list) {
        idMap.insert({ id, 0 });
    }

    vector<int> idxs;
    while (report_unq.size() != 0) {
        idxs.clear();
        string t_name = report_unq[0][1]; // 첫 번째 피신고인
        for (int i = 0; i < report_unq.size(); i++) {
            if (report_unq[i][1] == t_name) {
                idxs.push_back(i);
            }
        }
        if (idxs.size() >= k) {
            for (int idx : idxs) {
                idMap[(report_unq[idx][0])]++;
            }
        }
        for (int i = idxs.size() - 1; i >= 0; i--) {
            report_unq.erase(report_unq.begin()+idxs[i]);            
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(idMap[id_list[i]]);
    }

    return answer;
}

int main() {
    vector<string> id_list;
    vector<string> report;
    vector<int> expected;
    vector<int> calculated;
    int k;

    id_list = { "muzi", "frodo", "apeach", "neo" };
    report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    k = 2;
    expected = { 2, 1, 1, 0 };
    calculated = solution(id_list, report, k);
    if (expected == calculated) { cout << "Correct\n"; } else cout << "Wrong" << '\n';

    id_list = { "con", "ryan" };
    report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    k = 3;
    expected = { 0, 0 };
    calculated = solution(id_list, report, k);
    if (expected == calculated) { cout << "Correct\n"; }
    else cout << "Wrong" << '\n';


}