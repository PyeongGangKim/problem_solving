#include <iostream>
#include <deque>
#include <string>

using namespace std;

string cmd;
deque<int> dq;
int n;
bool isReverse;
bool doCmd(){
    for(int i = 0 ; i < cmd.length() ; i++){
        if(cmd[i] == 'R') isReverse = (isReverse) ? false : true;
        else{
           if(dq.empty()) return false; 
           if(isReverse){
               dq.pop_back();
           }
           else{
               dq.pop_front();
           }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int testcase;
    char temp;
    cin >> testcase;
    while(testcase--){
        isReverse = false;
        dq.clear();
        cin >> cmd;
        cin >> n;
        string num = "";
        while(1){
            cin >> temp;
            if(temp == ']') {
                if(num != ""){
                    dq.push_back(stoi(num));
                }
                break;
            }
            else if(temp == '[') continue;
            else if(temp == ','){
                dq.push_back(stoi(num));
                num = "";
            }
            else{
                num += temp;
            }
        }
        if(doCmd()){
            cout << "[";
            if(isReverse){
                for(int i = dq.size() - 1 ; i >= 0 ; i--){
                    cout << dq[i];
                    if(i != 0) cout << ",";
                }
            }
            else{
                for(int i = 0 ; i < dq.size() ; i++){
                    cout << dq[i];
                    if(i != dq.size()-1) cout << ",";
                }
            }
            cout << "]\n";
        }
        else{
            cout << "error\n";
        }
    }
}