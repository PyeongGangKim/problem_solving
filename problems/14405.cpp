#include <iostream>
#include <queue>
#include <string>

#define NOTHING 0
#define pi 1
#define ka 2
#define chu 3
using namespace std;

queue<char> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for(int i = 0 ; i < str.length() ; i++){
        q.push(str[i]);
    }
    int cur = NOTHING;
    char temp;
    int chuCnt = 0;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(cur == NOTHING){
            if(temp == 'p') cur = pi;
            else if(temp == 'k') cur = ka;
            else if(temp == 'c') {
                chuCnt = 1;
                cur = chu;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else if(cur == pi){
            if(temp == 'i') cur = NOTHING;
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else if(cur == ka){
            if(temp == 'a') cur = NOTHING;
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else if(cur == chu){
            if(chuCnt == 1 && temp == 'h') chuCnt = 2;
            else if(chuCnt == 2 && temp == 'u'){
                chuCnt = 0;
                cur = NOTHING;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
    }
    if(cur != NOTHING) cout << "NO\n";
    else cout << "YES\n";
}