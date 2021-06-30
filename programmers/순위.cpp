#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;


bool check[101];
int cnt[101];
void bfs(int n, vector<int> *node){
    queue<int> q;
    q.push(n);
    check[n] = true;
    int temp = 0;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i = 0 ; i < node[num].size() ; i++){
            if(!check[node[num][i]]){
                temp++;
                check[node[num][i]] = true;
                q.push(node[num][i]);
            }
        }
    }
    cnt[n] += temp;
}
int solution(int n, vector<vector<int> > results) {
    int answer = 0;
    vector<int> parent[101];// parent 구할 때 사용하는 용도
    vector<int> child[101];//child구할 때 사용하는 용도
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0 ; i < results.size() ; i++){
        parent[results[i][1]].push_back(results[i][0]); // 거꾸로 입력
        child[results[i][0]].push_back(results[i][1]);
    }
    for(int i = 1 ; i <= n ; i++){
        memset(check, false, sizeof(check));
        bfs(i, parent);
    }
    for(int i = 1 ; i <= n ; i++){
        memset(check, false, sizeof(check));
        bfs(i, child);
    }
    for(int i = 1 ; i <= n ; i++){
        if(cnt[i] == n-1) answer++;
    }
    return answer;
}