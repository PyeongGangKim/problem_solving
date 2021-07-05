#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<char> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string result = "";
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    int bomb_len = bomb.length();
    int str_len = str.length();
    vector<char> temp;
    for(int i = 0 ; i < str_len ; i++){
        temp.push_back(str[i]);
        if(temp.size() < bomb_len) continue;
        if(temp.back() == bomb[bomb_len - 1]){
            bool check = true;
            for(int j = 2 ; j <= bomb_len ; j++){
                if(temp[temp.size() - j] != bomb[bomb_len - j]) {
                    check = false;
                    break;
                }
            }
            if(check){
                temp.erase(temp.end() - bomb_len , temp.end());
            }
        }
    }
    if(temp.empty()) result = "FRULA";
    else{
        for(int i = 0 ; i < temp.size() ; i++){
            result += temp[i];
        }
    }
    
    cout << result << "\n";
}