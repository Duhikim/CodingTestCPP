#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class RowData {
private:
    int name;
    RowData* prev;
    RowData* post;

public:    
    RowData(int name) {
        this->name = name;
        this->prev = nullptr;
        this->post = nullptr;
    }

    void setPrev(RowData& data) {
        this->prev = &data;        
    }
    void setPost(RowData& data) {
        this->post = &data;
    }
    int getName() {
        return name;
    }
    RowData& getPrev() {
        return *(this->prev);
    }
    RowData& getPost() {
        return *(this->post);
    }
    RowData& remove() {
        prev->setPost(*post);
        post->setPrev(*prev);
        if (post->getName() < 0 ) return *prev;
        return *post;
    }
    void restore() {
        prev->setPost(*this);
        post->setPrev(*this);
    }
};

class DataPointer {
private:
    vector<RowData> dataList;
    deque<RowData*> deletedData;    
    RowData* cursor;
public:
    DataPointer(int n, int k) {                    
        for (int i = 0; i < n; i++) {
            RowData data(i);
            dataList.push_back(data);           
        }        
        RowData dataEnd(-1);
        dataList.push_back(dataEnd);   //n             
        RowData dataBegin(-2);
        dataList.push_back(dataBegin); // n+1
        
        for (int i = 1; i < n + 1; i++) {
            dataList[i].setPrev(dataList[i - 1]);
            dataList[i].setPost(dataList[i + 1]);
        }
        dataList[0].setPost(dataList[1]);
        dataList[0].setPrev(dataList[n + 1]);
        dataList[n + 1].setPost(dataList[0]);
        cursor = &dataList[k];
    }
    RowData* getCursor() {
        return cursor;
    }
    void up(int X) {
        while (X--) {
            cursor = &(cursor->getPrev());
        }
    }
    void down(int X) {
        while (X--) {
            cursor = &(cursor->getPost());            
        }
    }
    void deleteData() {
        deletedData.push_back(cursor);
        cursor = &(cursor->remove());
    }
    void undoDelete() {
        RowData* restoring = deletedData.back();
        deletedData.pop_back();
        restoring->restore();
    }
    deque<RowData*> getDeletedData() {
        return deletedData;
    }
        
};

string solution(int n, int k, vector<string> cmd) {
    DataPointer dataPointer(n, k);

    for (string command : cmd) {        
        int X=0;
        switch (command[0]) {
        case 'U': 
            X = stoi(command.substr(2));
            dataPointer.up(X);
            break;
        case 'D': 
            X = stoi(command.substr(2));
            dataPointer.down(X);
            break;
        case 'C': 
            dataPointer.deleteData();
            break;
        case 'Z': 
            dataPointer.undoDelete();
            break;
        }
    }    
    string answer(n, 'O');
    for (RowData* data : dataPointer.getDeletedData()) {
        answer[data->getName()] = 'X';
    }
    return answer;
}

int main() {
    int n, k;
    vector<string> cmd;

    n = 8;
    k = 2;
    cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
    cout << solution(n, k, cmd);

    return 0;

}