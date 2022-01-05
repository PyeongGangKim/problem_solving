#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
vector<pair<int,int> > lights[101][101];
bool onOff[101][101];
bool isChecked[101][101];
int mX[] = {0,0,-1,1};
int mY[] = {-1,1,0,0};
int res = 1;
int bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    isChecked[1][1] = true;
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < lights[x][y].size() ; i++){
            int xOn = lights[x][y][i].first; int yOn = lights[x][y][i].second;
            if(!onOff[xOn][yOn]) {
                cnt++;
                onOff[xOn][yOn] = true;
            }
        }
        for(int i = 0 ; i < 4 ; i++){
            int nX = x + mX[i]; int nY = y + mY[i];
            if(nX < 1 || nX > N || nY < 1 || nY > N) continue;
            if(!onOff[nX][nY] || isChecked[nX][nY]) continue;
            isChecked[nX][nY] = true;
            q.push(make_pair(nX,nY));
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        lights[x][y].push_back(make_pair(a,b));
    }
    onOff[1][1] = true;
    while(1){
        memset(isChecked, false, sizeof(isChecked));
        int tmp = bfs();
        if(!tmp) break;
        res += tmp;
    }
    cout << res << "\n";
}