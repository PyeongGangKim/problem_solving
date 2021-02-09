#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num, tempNum;
    cin >> num;
    queue<int> q;
    while(num--){
        char temp[10];
        cin >> temp;
        if(strcmp(temp, "push") == 0) {
            cin >> tempNum;
            q.push(tempNum);
        }
        else if(strcmp(temp, "pop") == 0){
            if(q.empty()) cout << "-1" << "\n";
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(strcmp(temp, "size") == 0) cout << q.size() << "\n";
        else if(strcmp(temp, "empty") == 0){
            if(q.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if(strcmp(temp, "back") == 0){
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.back() << "\n";
        }
        else{
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.front() << "\n";
        }
    
    }
}