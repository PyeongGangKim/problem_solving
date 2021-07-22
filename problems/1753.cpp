#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int INF = 1e9;
vector<pair<int, int> > v[20001];
int d[20001];
int V,E;

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair<int, int> > > pq; // Minheap만들기
    pq.push(make_pair(0,start)); // 시작점 먼저 넣기
    while(!pq.empty()){
        int cur = pq.top().second; // 현재 탐색할 노드
        int dist = pq.top().first; // 이전꺼와 연결된 노드의 크기.
        pq.pop();
        if(d[cur] < dist) continue; // dist가 현재꺼 보다 크면 볼필요도 없음
        for(int i = 0 ; i < v[cur].size() ; i++){ // 현재 노드와 연결된 것과 이전의 연결된 edge와의 크기와 현재 크기와 비교하여 넣기.
            int next = v[cur][i].first;
            int nextDist = v[cur][i].second + dist;
            if(nextDist < d[next]){ // 만약 cur와 연결된 것의 통로가 더 작다면 교체
                d[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int start;
    int s_node, e_node, dist;
    
    
    cin >> V >> E;
    cin >> start;
    for(int i = 1 ; i <= V ; i++){
        d[i] = INF; // 초기화
    }

    for(int i = 0 ; i < E ; i++){
        cin >> s_node >> e_node >> dist;
        v[s_node].push_back(make_pair(e_node, dist));
    }
    dijkstra(start);
    for(int i = 1 ; i <= V ; i++){
        if(d[i] == INF) cout<< "INF" << "\n";
        else cout << d[i] << "\n";
    }
    
}