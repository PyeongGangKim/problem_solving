#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int parent[MAX];
bool college[MAX]; // 남자 true, 여자 false
int N, M;
int cnt = 0;
int res = 0;

priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int,int> > > >pq;

int Find(int n){
    if(parent[n] == n) return n;
    else return Find(parent[n]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    parent[y] = x;

}
void init(){
    for(int i = 1 ; i <= N ; i++){
        parent[i] = i;
    }
}

int bfs(){
    // 먼저 priority_queue에서 하나를 꺼내서 간선과 연결되어있는 노드가 다른 성별인지 체크
    // 다른 성별이라면, parent가 같은지 체크
    while(!pq.empty()){
        int num = pq.top().first; int n1 = pq.top().second.first; int n2 = pq.top().second.second;
        pq.pop();
        if(college[n1] == college[n2]) continue;
        if(Find(n1) == Find(n2)) continue;
        if(cnt == N - 1) return res;
        //연결하기
        Union(n1,n2);
        res += num;
        cnt++;
    }
    if(cnt == N - 1) return res;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;
    init();
    char s;
    for(int i = 0 ; i < N ; i++){
        cin >> s;
        if(s == 'M') college[i+1] = true;
        else college[i+1] = false;
    }
    int n1, n2, num;
    for(int i = 0 ; i < M ; i++){
        cin >> n1 >> n2 >> num;
        pq.push(make_pair(num, make_pair(n1, n2)));
    }
    cout << bfs() << "\n";
}
