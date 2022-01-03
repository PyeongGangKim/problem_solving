#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;
bool isVisited[5001];
#define MAX 987654321
vector<pair<int,int> > tree[5001];
int dist[5001][5001];
int N, Q;

void dfs(int s, int n, int cur){
    for(int i = 0 ; i < tree[n].size() ; i++){
        if(isVisited[tree[n][i].first]) continue;
        isVisited[tree[n][i].first] = true;
        dist[s][tree[n][i].first] = min(cur,tree[n][i].second);
        dfs(s, tree[n][i].first, min(cur, tree[n][i].second));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    for(int i = 0 ; i < N - 1 ; i++){
        int s,e,d;
        cin >> s >> e >> d;
        tree[s].push_back(make_pair(e,d));
        tree[e].push_back(make_pair(s,d));
    }

    for(int i = 1 ; i <= N ; i++){
        memset(isVisited, false, sizeof(isVisited));
        isVisited[i] = true;
        dfs(i, i, MAX);
    }
 
    for(int i = 0 ; i < Q ; i++){
        int k,v;
        cin >> k >> v;
        int cnt = 0;
        for(int i = 1 ; i <= N ; i++){
            if(dist[v][i] >= k) cnt++;
        }
        cout << cnt << "\n";
    }
}