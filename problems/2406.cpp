#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 1001

using namespace std;

priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
vector<pair<int,int> > res;

int n,m;
int distRes = 0;
int parent[MAX];
int cnt = 0;

int Find(int a){
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a > b) parent[a] = b;
    else parent[b] = a;
    
}
void init(){
    for(int i = 1 ; i <= n ; i++){
       parent[n] = n;
    }
}
void Kruscal(){
    while(!pq.empty()){
        int dist = pq.top().first;
        int x = pq.top().second.first; int y = pq.top().second.second;
        pq.pop();
        if(Find(x) == Find(y)) continue;
        Union(x,y);
        distRes += dist;
        res.push_back(make_pair(x,y));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    int a,b, temp;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        if(Find(a) != Find(b)){
            Union(a,b);
        }
        
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a;
            if(i == 1 || j == 1) continue;
            if(i < j) continue;
            pq.push(make_pair(a, make_pair(i,j)));
        }
    }
    Kruscal();
    cout << distRes << " " << res.size() << "\n";
    if(res.size() != 0){
        for(int i = 0 ; i < res.size() ; i++){
            cout << res[i].second << " " << res[i].first << "\n";
        }
    }
    
    
}