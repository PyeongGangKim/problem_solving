#include <iostream>
#include <queue>
#include <cstring>

#define MAX 1001

using namespace std;

int check[MAX][MAX][2];
int map[MAX][MAX];
int N, M;
int s_n, s_m;
int e_n, e_m;
int n_move[4] = {0,0,1,-1};
int m_move[4] = {1,-1,0,0};

int bfs(){
    queue<pair<int, pair<int,int> > > q; //지팡이 사용여부, n,m
    q.push(make_pair(0,make_pair(s_n, s_m)));
    check[s_n][s_m][0] = 1;
    while(!q.empty()){
        int isUsed = q.front().first;
        int c_n = q.front().second.first; int c_m = q.front().second.second;
       
        q.pop();
        if(c_n == e_n && c_m == e_m){
            return check[c_n][c_m][isUsed] - 1;
        }
        for(int i = 0 ; i < 4 ; i++){
            int n_n = c_n + n_move[i]; int n_m = c_m + m_move[i];
            if(n_n < 1 || n_n > N || n_m < 1 || n_m > M) continue;
            if(map[n_n][n_m] == 1 && !isUsed && check[n_n][n_m][1] == 0){ // 사용하지 않았고, 벽을 뚫었을 때, 방문하지 않았는지 여부 체크.
                check[n_n][n_m][1] = check[c_n][c_m][isUsed] + 1;
                q.push(make_pair(1, make_pair(n_n, n_m)));
            }
            if(map[n_n][n_m] == 0 && check[n_n][n_m][isUsed] == 0){
                check[n_n][n_m][isUsed] = check[c_n][c_m][isUsed] + 1;
                q.push(make_pair(isUsed, make_pair(n_n, n_m)));
                
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // memset(check, 0, sizeof(check));
    cin >> N >> M;
    cin >> s_n >> s_m >> e_n >> e_m;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ;j++){
            cin >> map[i][j];
        }
    }
    cout << bfs() << "\n"; 

}