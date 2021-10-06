#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;


int N, M;

int map[MAX][MAX];
int visit[MAX][MAX]; // 치즈와 외부 공기 내부 공기 비교
 
vector<pair<pair<int,int>, bool> > cheeseList; // input 치즈 list
vector<pair<int,int> > meltCheeseList; // 녹일 치즈 list
queue<pair<int,int> > changedAir; // 현재 바뀐 공기들 change

int mX[4] = {0,0,-1,1};
int mY[4] = {1,-1,0,0};

bool allDone(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 1) return false;
        }
    }
    return true;
}
void divide_air(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nX = mX[i] + x ; int nY = mY[i] +y;
            if(nX < 0 || nX >= N || nY < 0 || nY >= M) continue;
            if(visit[nX][nY] == 0){
                visit[nX][nY] = 1;
                q.push(make_pair(nX,nY));
            }
        }
    }
}
void find_cheese(){
    meltCheeseList.clear();
    for(int i = 0 ; i < cheeseList.size() ; i++){
        if(cheeseList[i].second == true) continue;
        int x = cheeseList[i].first.first; int y = cheeseList[i].first.second;
        int cnt = 0;
        for(int i = 0 ; i < 4 ; i++){
            int nX = mX[i] + x ; int nY = mY[i] + y;
            if(nX < 0 || nX >= N || nY < 0 || nY >= M || visit[nX][nY] == 1){
                cnt++;
            }
        }
        if(cnt >= 2){
            meltCheeseList.push_back(make_pair(x,y));
            cheeseList[i].second = true;
        }
    }
}
void melt_cheese(){
    for(int i = 0 ; i < meltCheeseList.size() ; i++){
        int x = meltCheeseList[i].first; int y = meltCheeseList[i].second;
        changedAir.push(make_pair(x,y));
        visit[x][y] = 0;
        map[x][y] = 0;
    }
}

void connetAir(){
    while(!changedAir.empty()){
        int x = changedAir.front().first; int y = changedAir.front().second;
        changedAir.pop();
        visit[x][y]= 1;
        for(int i = 0 ; i < 4 ; i++){
            int nX = mX[i] + x ; int nY = mY[i] +y;
            if(nX < 0 || nX >= N || nY < 0 || nY >= M) continue;
            if(visit[nX][nY] == 0){
                visit[nX][nY] = 1;
                changedAir.push(make_pair(nX,nY));
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                visit[i][j] = 2;
                cheeseList.push_back(make_pair(make_pair(i,j), false)); // 녹은 cheese일 경우 true로 변경
            }
        }
    }

    
    int cnt = 0;
    divide_air();
    while(1){
        if(allDone()) break;
        find_cheese();
        melt_cheese();
        connetAir();
        cnt++;
    }
    cout << cnt << "\n";
    
}