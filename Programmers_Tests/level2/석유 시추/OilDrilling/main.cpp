#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
bool debug = //true;
            false;


int counter;
enum Direction {    
    Up,
    Down,
    Left,
    Right
};

class point_data {
public:
    int index;    
    bool searched;
};

void Searching(vector<vector<int>>& land, vector<vector<point_data>>& DataVector, int direction, int i, int j);
void Data_reset(vector<vector<point_data>>& DataVector) {
    for (int i = 0; i < DataVector.size(); i++) {
        for (int j = 0; j < DataVector[0].size(); j++) {
            DataVector[i][j].searched = false;
            DataVector[i][j].index = -1;
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;    
    int Column = land[0].size(), Row = land.size(); //가로, 세로 길이
        
    vector<int> quantity_by_index;
    vector<int> quantity_by_col(Column, 0);
        
    vector<vector<point_data>> DataVector(Row, vector<point_data>(Column));
    Data_reset(DataVector);

    int Current_index = -1;

    for (int j = 0; j < Column; j++) {            
        for (int i = 0; i < Row; i++) {
            counter = 0;
            if (land[i][j] && !DataVector[i][j].searched) {
                counter++;
                DataVector[i][j].index = ++Current_index;
                DataVector[i][j].searched = true;
                if (j + 1 < Column) {
                    if (land[i][j + 1] && !DataVector[i][j + 1].searched) {
                        DataVector[i][j + 1].index = DataVector[i][j].index;
                        Searching(land, DataVector, Right, i, j + 1);
                    }
                }
                if (j > 0) {
                    if (land[i][j - 1] && !DataVector[i][j - 1].searched) {
                        DataVector[i][j - 1].index = DataVector[i][j].index;
                        Searching(land, DataVector, Left, i, j - 1);           
                    }
                }
                if (i > 0) {
                    if (land[i - 1][j] && !DataVector[i - 1][j].searched) {
                        DataVector[i-1][j].index = DataVector[i][j].index;
                        Searching(land, DataVector, Up, i - 1, j);
                    }
                }
                if (i+1 < Row) {
                    if (land[i + 1][j] && !DataVector[i + 1][j].searched) {
                        DataVector[i + 1][j].index = DataVector[i][j].index;
                        Searching(land, DataVector, Down, i + 1, j);
                    }
                }
            }
            if (counter > 0)
                quantity_by_index.push_back(counter);
        }
       
    }
   
    if (debug) {
        cout << "인덱스 별 기름 양\n";
        cout << "index \t 기름양\n";
        for (int i = 0; i < quantity_by_index.size(); i++) {
            cout << i << '\t' << quantity_by_index[i] << '\n';
        }
    }

    for (int j = 0; j < Column; j++) {
        map<int, int> Index_Size;
        for (int i = 0; i < Row; i++) {
            if (DataVector[i][j].index >= 0) {
                Index_Size.insert({ DataVector[i][j].index, quantity_by_index[DataVector[i][j].index] });
            }
        }
        if (Index_Size.size()) {
            for (auto& IS_pair : Index_Size) {
                quantity_by_col[j] += IS_pair.second;
            }
        }
    }

    answer = *max_element(quantity_by_col.begin(), quantity_by_col.end());
    return answer;
}

void Searching(vector<vector<int>>& land, vector<vector<point_data>>& DataVector, int direction, int i, int j) {
    counter++;
    DataVector[i][j].searched = true;

    switch (direction) {
    case Up:
        if (i > 0 && land[i - 1][j] && !DataVector[i - 1][j].searched) {
            DataVector[i - 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Up, i - 1, j);
        }
        if (j > 0 && land[i][j - 1] && !DataVector[i][j - 1].searched) {
            DataVector[i][j - 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Left, i, j - 1);
        }
        if (j + 1 < land[0].size() && land[i][j + 1] && !DataVector[i][j + 1].searched) {
            DataVector[i][j + 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Right, i, j + 1);
        }
        break;

    case Left:
        if (i > 0 && land[i - 1][j] && !DataVector[i - 1][j].searched) {
            DataVector[i - 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Up, i - 1, j);
        }
        if (j > 0 && land[i][j - 1] && !DataVector[i][j - 1].searched) {
            DataVector[i][j - 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Left, i, j - 1);
        }
        if (i + 1 < land.size() && land[i + 1][j] && !DataVector[i + 1][j].searched) {
            DataVector[i + 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Down, i + 1, j);
        }
        break;

    case Right:
        if (i > 0 && land[i - 1][j] && !DataVector[i - 1][j].searched) {
            DataVector[i - 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Up, i - 1, j);
        }
        if (j + 1 < land[0].size() && land[i][j + 1] && !DataVector[i][j + 1].searched) {
            DataVector[i][j + 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Right, i, j + 1);
        }
        if (i + 1 < land.size() && land[i + 1][j] && !DataVector[i + 1][j].searched) {
            DataVector[i + 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Down, i + 1, j);
        }
        break;

    case Down:
        if (j + 1 < land[0].size() && land[i][j + 1] && !DataVector[i][j + 1].searched) {
            DataVector[i][j + 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Right, i, j + 1);
        }
        if (j > 0 && land[i][j - 1] && !DataVector[i][j - 1].searched) {
            DataVector[i][j - 1].index = DataVector[i][j].index;
            Searching(land, DataVector, Left, i, j - 1);
        }
        if (i + 1 < land.size() && land[i + 1][j] && !DataVector[i + 1][j].searched) {
            DataVector[i + 1][j].index = DataVector[i][j].index;
            Searching(land, DataVector, Down, i + 1, j);
        }
        break;

    }
}


int main() {
    vector<vector<int>> land1 {
        {0, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 0, 0}, 
        {1, 1, 0, 0, 0, 1, 1, 0}, 
        {1, 1, 1, 0, 0, 0, 0, 0}, 
        {1, 1, 1, 0, 0, 0, 1, 1}
    };
    cout << "예상 닶 : 9, \t 도출 답 : " << solution(land1) << '\n'; //예상 닶 9

    vector<vector<int>> land2{
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1}
    };
    cout << "예상 닶 : 16, \t 도출 답 : " << solution(land2) << '\n'; //예상 닶 16

    return 0;
}