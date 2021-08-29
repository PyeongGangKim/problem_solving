#include <iostream>
#include <queue>


using namespace std;


int INF = 1e9;

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};

int map[125][125];
int d[125][125];
int N;
void dijkstra(){
    d[0][0] = map[0][0];
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq; // minheap
    pq.push(make_pair(map[0][0],make_pair(0,0)));
    while(!pq.empty()){
        int curDist = pq.top().first;
        int curX = pq.top().second.first; int curY = pq.top().second.second;
        pq.pop();//내보내기
        if(d[curX][curY] < curDist) continue;//현재 크기가 pq에서 나온 dist보다 작다면 그냥 pass
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + moveX[i]; int nextY = curY + moveY[i];
            //만약 nextX < 0 or nextX >= N or nextY < 0 or nextY >= N이면 패스
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
            int nextDist = curDist + map[nextX][nextY];
            if(nextDist < d[nextX][nextY]){//현재 저장되어 있는 거리보다 nextDist가 더 작다면 nextDist 저장
                d[nextX][nextY] = nextDist;
                pq.push(make_pair(nextDist, make_pair(nextX, nextY)));
            } 
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int cnt = 0;
    while(1){
        cnt++;
        cin >> N;
        if(N == 0) break;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cin >> map[i][j];
                d[i][j] = INF;
            }
        }
        dijkstra();
        cout << "Problem " << cnt << ": " << d[N-1][N-1] << "\n";
    }
}