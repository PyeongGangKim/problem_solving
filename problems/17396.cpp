#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAX 100001
#define INF 1e11
typedef long long ll;
using namespace std;

vector<pair<int,int> > edge[MAX];
int N,M;
bool isPossible[MAX];
ll Distance[MAX];

void dijkstra(){
    Distance[0] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int cur = pq.top().second;
        ll curDist = pq.top().first;
        pq.pop();
        // cout << cur << " " << curDist << " " << Distance[cur] << "\n";
        if(curDist > Distance[cur]) continue;
        for(int i = 0 ; i < edge[cur].size() ; i++){
            int next = edge[cur][i].first;
            ll nextDist = curDist + edge[cur][i].second;
            // cout << next << " " << nextDist << " " << Distance[next] << " " << isPossible[next] << "\n";
            if(nextDist < Distance[next]){
                Distance[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }
}
void init(){
    for(int i = 0 ; i < N ; i++){
        Distance[i] = INF;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;
    init();
    for(int i = 0 ; i < N ; i++){
        int n;
        cin >> n;
        if(n == 0){
            isPossible[i] = true;
        }
        else isPossible[i] = false;
    }
    isPossible[N-1] = true;
    for(int i = 0 ; i < M ; i++){
        int n1,n2, dist;
        cin >> n1 >> n2 >> dist;
        if(isPossible[n1] && isPossible[n2]){
            edge[n1].push_back(make_pair(n2,dist));
            edge[n2].push_back(make_pair(n1,dist));
        }
        
    }
    dijkstra();
    if(Distance[N-1] == INF) cout << "-1\n";
    else cout << Distance[N-1] << "\n";
}