#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string,int> um;
    int N;
    cin >> N;
    int cnt = 0;
    string res;
    for(int i = 0 ; i < N ; i++){
        string title;
        cin >> title;
        if(um.find(title) != um.end()){ // 현재 있다면,
            um[title]++;
            if(cnt < um[title]){
                cnt = um[title];
                res = title;
            }
            if(cnt == um[title]){
                if(title < res){
                    res = title;
                }
            }
        }
        else{
            um[title] = 1;
            if(cnt < um[title]){
                cnt = um[title];
                res = title;
            }
            if(cnt == um[title]){
                if(title < res){
                    res = title;
                }
            }
        }
    }
    cout << res << "\n";
}