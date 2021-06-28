#include <string>
#include <vector>
#include <cstring>
const int max = 201;
bool check[max];

using namespace std;
void dfs(int n, vector<vector<int>> computers){
    for(int i = 0 ; i < computers[n].size() ; i++){
        if(computers[n][i] && !check[i]){
            check[i] = true;
            dfs(i, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(check, false, sizeof(check));
    for(int i = 0 ; i < computers.size() ; i++){
        if(!check[i]){
            check[i] = true;
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}