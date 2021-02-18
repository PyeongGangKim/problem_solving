#include <iostream>
#include <vector>

using namespace std;

vector<char> frontCursor;
vector<char> backCursor;

void concate(){
    while(!backCursor.empty()){
        frontCursor.push_back(backCursor.back());
        backCursor.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string temp;
    cin >> temp;
    for(int i = 0 ; i < temp.length() ; i++){
        frontCursor.push_back(temp[i]);
    }
    int num ; 
    cin >> num;
    char command;
    while(num--){
        cin >> command;
        if(command == 'P'){
            cin >> command;
            frontCursor.push_back(command);
        }
        else if(command == 'L'){
            if(frontCursor.empty()) continue;
            backCursor.push_back(frontCursor.back());
            frontCursor.pop_back();
        }
        else if(command == 'D'){
            if(backCursor.empty()) continue;
            frontCursor.push_back(backCursor.back());
            backCursor.pop_back();
        }
        else{
            if(frontCursor.empty()) continue;
            frontCursor.pop_back();
        }
    }
    concate();
    for(int i = 0 ; i < frontCursor.size() ; i++){
        cout << frontCursor[i];
    }
    cout << "\n";
}