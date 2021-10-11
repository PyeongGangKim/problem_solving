#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> student[501];
bool countS[501][501];
int cnt[501];

void dijkstra(int n){
    countS[n][n] = true;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0 ; i < student[cur].size() ; i++){
            int next = student[cur][i];
            if(!countS[n][next]){
                q.push(next);
                countS[n][next] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int shortH, tallH;
    memset(student, false, sizeof(student));
    memset(countS, false, sizeof(countS));
    for(int i = 0 ; i < M ; i++){
        cin >> shortH >> tallH;
        student[shortH].push_back(tallH);
    }
    
    for(int i = 1 ; i <= N ; i++){
        dijkstra(i);
    }
    int res = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(countS[i][j]){
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    for(int i = 1 ; i <= N ; i++){
        if(cnt[i] == N+1) res++;
    }
    cout << res << "\n";
}