#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num, tempNum;
    cin >> num;
    deque<int> dq;
    while(num--){
        char temp[20];
        cin >> temp;
        if(strcmp(temp, "push_front") == 0) {
            cin >> tempNum;
            dq.push_front(tempNum);
        }
        else if(strcmp(temp, "push_back") == 0) {
            cin >> tempNum;
            dq.push_back(tempNum);
        }
        else if(strcmp(temp, "pop_front") == 0){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(strcmp(temp, "pop_back") == 0){
            if(dq.empty()) cout << "-1" << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(strcmp(temp, "size") == 0) cout << dq.size() << "\n";
        else if(strcmp(temp, "empty") == 0){
            if(dq.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(strcmp(temp, "back") == 0){
            if(dq.empty()) cout << "-1" << "\n";
            else cout << dq.back() << "\n";
        }
        else{
            if(dq.empty()) cout << "-1" << "\n";
            else cout << dq.front() << "\n";
        }
    
    }
}