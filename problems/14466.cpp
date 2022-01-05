#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;
int N,K,R;

set<pair<int,int> > bridges[101][101];
bool isVisited[101][101];

vector<pair<int,int> > cows;

int mX[] = {0,0,1,-1};
int mY[] = {1,-1,0,0};
void dfs(int r, int c){

    isVisited[r][c] = true;
    for(int i = 0 ; i < 4 ; i++){
        int nR = r + mX[i] ; int nC = c + mY[i];
        if(nR < 1 || nR > N || nC < 1 || nC > N) continue;
        if(isVisited[nR][nC] || bridges[r][c].count(make_pair(nR,nC))) continue;
        dfs(nR, nC);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> R;

    for(int i = 0 ; i < R ; i++){
        int r,c,r1,c1;
        cin >> r >> c >> r1 >> c1;
        bridges[r][c].insert(make_pair(r1,c1));
        bridges[r1][c1].insert(make_pair(r,c));
    }
    for(int i = 0 ; i < K ; i++){
        int r,c;
        cin >> r >> c;
        cows.push_back(make_pair(r,c));
    }
    int ans = 0;
    for(int i = 0 ; i < K ; i++){
        memset(isVisited, false, sizeof(isVisited));
        dfs(cows[i].first, cows[i].second);
        for(int j = i+1 ; j < K ; j++){
            if(!isVisited[cows[j].first][cows[j].second]) ans++;
        }
    }
    cout << ans << "\n";
}