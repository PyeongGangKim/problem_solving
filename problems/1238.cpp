#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 1e9

using namespace std;
vector<pair<int,int> > edge[MAX];
int Dist[MAX][MAX];

int N, M, X;

void dijkstra(int start){
    Dist[start][start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if(curDist > Dist[start][cur]) continue;
        for(int i = 0 ; i < edge[cur].size() ; i++){
            int next = edge[cur][i].first;
            int nextDist = curDist + edge[cur][i].second;
            if(Dist[start][next] > nextDist){
                Dist[start][next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }
}
void init(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            Dist[i][j] = INF;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    init();
    for(int i = 0 ; i < M ; i++){
        int n1, n2, dist;
        cin >> n1 >> n2 >> dist;
        edge[n1].push_back(make_pair(n2,dist));
    }
    for(int i = 1; i <= N ; i++){
        dijkstra(i);
    }
    int res = -1;
    for(int i = 1 ; i <= N ; i++){
        res = max(res, Dist[i][X] + Dist[X][i]);
    }
    cout << res << "\n";
}