
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> answer;
bool done = false;

void dfs(vector<bool> &check, vector<vector<string>> tickets, string cur, int n, vector<string> &temp){
    temp.push_back(cur);
    if(temp.size() == n + 1) {
        if(!done){
            done = true;
            answer = temp;    
        }

        return;   
    }
    else{
        for(int i = 0 ; i < n ; i++){
            if(!check[i] && tickets[i][0] == cur){
                check[i] = true;
                dfs(check, tickets, tickets[i][1], n, temp);
                check[i] = false;
            }
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> temp;
    int n = tickets.size();
    vector<bool> check(n, false);
    sort(tickets.begin(), tickets.end());
    dfs(check, tickets, "ICN", n, temp);

    return answer;
}