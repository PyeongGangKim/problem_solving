#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1e9
#define MAX 101

using namespace std;

vector<pair<int,int> > v[MAX];
int n,m,r;

int items[MAX];
int dist[MAX];

int res = -1;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void init(){
    for(int i = 1 ; i <= n ; i++){
        dist[i] = INF;
    }
}
void dijkstra(int x){
    init();
    dist[x] = 0;
    pq.push(make_pair(0,x));
    while(!pq.empty()){
        //지금꺼와 지금 연결되어 있는 노드들에 저장되어 있는 길이 체크 후 더 작은 거 넣기.
        int d = pq.top().first; int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < v[cur].size() ; i++){
            int nD = v[cur][i].second;
            int next = v[cur][i].first;
            if(dist[next] > nD + d){
                dist[next] = nD + d;
                pq.push(make_pair(nD + d, next));
            }
        }
    }
    int curItems = 0;
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] <= m) curItems += items[i];
    }
    res = max(res, curItems);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> r;
    for(int i = 1 ; i <= n ; i++){
        cin >> items[i];
    }
    int n1, n2, d;
    for(int i = 0 ; i < r ; i++){
        cin >> n1 >> n2 >> d;
        v[n1].push_back(make_pair(n2,d));
        v[n2].push_back(make_pair(n1,d));
    }
    for(int i = 1 ; i <= n ; i++){
        dijkstra(i);
    }
    cout << res << "\n";

}
