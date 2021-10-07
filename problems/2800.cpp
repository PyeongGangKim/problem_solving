#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool isPicked[11];
bool inputStr[201];
vector<pair<int,int> > gualho;
int gualhoNum;
vector<string> result;
string input;
void makeNewSik(){
    string newStr = "";
    for(int i = 0 ; i < input.length() ; i++){
        if(inputStr[i]) continue;
        newStr += input[i];
    }

    result.push_back(newStr);
}
void pickGualho(int idx, int cnt, int maxCnt){
    if(cnt == maxCnt){
        makeNewSik();
    }
    else{
        for(int i = idx ; i < gualhoNum ; i++){
            if(!isPicked[i]){
                isPicked[i] = true;
                inputStr[gualho[i].first] = true;
                inputStr[gualho[i].second] = true;
                pickGualho(i, cnt+1, maxCnt);
                inputStr[gualho[i].first] = false;
                inputStr[gualho[i].second] = false;
                isPicked[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    stack<int> temp;
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == '(') temp.push(i);
        else if(input[i] == ')'){
            int cur = temp.top();
            temp.pop();
            gualho.push_back(make_pair(cur,i));
        }
    }
    memset(isPicked, false, sizeof(isPicked));
    memset(inputStr, false, sizeof(inputStr));
    gualhoNum = gualho.size();
    for(int i = 1 ; i <= gualhoNum ; i++){
        pickGualho(0,0,i);
    }
    sort(result.begin(), result.end());
    cout << result[0] << "\n";
    string prev = result[0];
    for(int i = 1 ; i < result.size() ; i++){
        if(prev.compare(result[i]) != 0){
            cout << result[i] << "\n";
        }
        prev = result[i];
    }
}