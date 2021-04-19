#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

vector<pair<int,int> > v;
vector<int> graph[101];
bool check[101];
int n;

int makeEdge(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);

}
void clearGraph(){
    for(int i = 0 ; i < n+2 ; i++){
        graph[i].clear();
    }
}
bool BFS(){
    queue<int> q;
    q.push(0);
    check[0] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == n+1) return true;
        for(int i = 0 ; i < graph[cur].size() ; i++){
            int next = graph[cur][i];
            if(check[next]) continue;
            check[next] = true;
            q.push(next);
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testcase;
    cin >> testcase;

    while(testcase--){
        cin >> n;
        int x,y;
        for(int i = 0 ; i < n+2 ; i++){
            cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        for(int i = 0 ; i < n+2 ; i++){
            for(int j = i ; j < n+2 ; j++){
                int dist = makeEdge(v[i], v[j]);
                int remain = (dist % 50) != 0 ? 1 : 0;
                if(dist/50 + remain <= 20){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        memset(check,false, sizeof(check));
        if(BFS()) cout << "happy\n";
        else cout << "sad\n";
        v.clear();
        clearGraph();
    }

}