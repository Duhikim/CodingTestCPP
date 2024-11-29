#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
   
    enum Category { 
        Code = 0, 
        Date = 1, 
        Maximum = 2, 
        Remain = 3 };

    int ExtCat, SortCat;
    if (ext == "code") ExtCat = Code;
    else if (ext == "date") ExtCat = Date;
    else if (ext == "maximum") ExtCat = Maximum;
    else ExtCat = Remain;

    if (sort_by == "code") SortCat = Code;
    else if (sort_by == "date") SortCat = Date;
    else if (sort_by == "maximum") SortCat = Maximum;
    else SortCat = Remain;

    for (auto iter = data.begin(); iter != data.end(); iter++) {
        if ((*iter)[ExtCat] > val_ext)
        {
            data.erase(iter--);            
        }
    }
    
    sort(data.begin(), data.end(), [SortCat](vector<int>& a, vector<int>& b)->bool {return a[SortCat] < b[SortCat]; });


    return data;
}

int main() {

    vector<vector<int>> data1 = {
        {1, 20300104, 100, 80},
        {2, 20300804, 847, 37},
        {3, 20300401, 10, 8}
    };
    string ext1 = "date", sort_by1 = "remain";
    int val_ext1 = 20300501;

    for (vector<int> a : solution(data1, ext1, val_ext1, sort_by1)) {
        for (int b : a) {
            cout << b << " , ";
        }
        cout << '\n';
    }


    return 0;
}