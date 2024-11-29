#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> playerRank_of;

    for (int i = 0; i < players.size(); i++) {
        playerRank_of[players[i]] = i;
    }
    
    for (auto passingMan : callings) {
        int Passing = playerRank_of[passingMan];
        int Passed = Passing - 1;

        playerRank_of[players[Passing]] = Passed;
        playerRank_of[players[Passed]] = Passing;

        swap(players[Passing], players[Passed]);      
    }

    return players;
}


int main() {
    vector<string> players1 = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings1 = { "kai", "kai", "mine", "mine" };

    for (string str : solution(players1, callings1)) {
        cout << str << " -> ";
    } // ±â´ë°ª : ["mumu", "kai", "mine", "soe", "poe"]
    
    return 0;
}