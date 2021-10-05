#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>


#define MAX 51

#define INF 987654321

using namespace std;

int mX[4] = {0,0,1,-1};
int mY[4] = {1,-1,0,0};

int dist[MAX][MAX];
int map[MAX][MAX];
int n;

void dijkstra(){
    priority_queue<pair<int, pair<int,int > >, vector<pair<int, pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq; // min heap
    pq.push(make_pair(0,make_pair(0,0)));
    dist[0][0] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int x = pq.top().second.first; int y = pq.top().second.second;
        pq.pop();
        if(cost > dist[x][y]) continue;
        for(int i = 0 ; i < 4 ; i++){
            int nX = mX[i] + x; int nY = mY[i] + y;
            if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
            if(dist[nX][nY] > cost + map[nX][nY]){
                dist[nX][nY] = cost + map[nX][nY];
                pq.push(make_pair(dist[nX][nY], make_pair(nX, nY)));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < n ; j++){
            if(temp[j] == '1'){
                map[i][j] = 0;
            }
            else{
                map[i][j] = 1;
            }
            dist[i][j] = INF;
        }
    }
    dijkstra();
    cout << dist[n-1][n-1] << "\n";

}