#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 300001

using namespace std;
int N, M, K, X;
vector<int> v[MAX];
vector<int> res;
bool check[MAX];

void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(X,0));
    check[X] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int num = q.front().second;
        q.pop();
        if(num > K) break;
        if(num == K) res.push_back(cur);
        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];
            if(check[next]) continue;
            q.push(make_pair(next,num+1));
            check[next] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(check, false, sizeof(check));

    cin >> N >> M >> K >> X;
    int from, to;
    for(int i = 0 ; i < M ; i++){
        cin >> from >> to;
        v[from].push_back(to);
    }
    bfs();
    if(res.empty()) cout << "-1\n";
    else{
        sort(res.begin(),res.end());
        for(int i = 0 ; i < res.size() ; i++){
            cout << res[i] << "\n";
        }
    }
}