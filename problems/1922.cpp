#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<pair <int, pair <int, int> > > graph;

int parent[100001];
int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}
bool isSameParent(int x, int y){
    if(find(x) == find(y)) return true;
    else return false;
}
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parent[y] = x;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int node1, node2, value;
    for(int i = 0 ; i < M ; i++){
        cin >> node1 >> node2 >> value;
        graph.push_back(make_pair(value,make_pair(node1,node2)));
    }
    sort(graph.begin(), graph.end());
    for(int i = 1 ; i <= N ; i++){
        parent[i] = i;
    }
    int result = 0;
    for(int i = 0 ; i < graph.size() ; i++){
        if(isSameParent(graph[i].second.first, graph[i].second.second)) continue;
        else{
            uni(graph[i].second.first, graph[i].second.second);
            result += graph[i].first;
        }
    }
    cout << result << "\n";

}
