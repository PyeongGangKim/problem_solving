#include <iostream>
#include <queue>
#include <cstring>

#define MAX 1000001

using namespace std;

int F,S,G,U,D;

bool check[MAX];

void bfs(){
    queue<pair<int,int> > q;
    check[S] = true;
    q.push(make_pair(S, 0));
    while(!q.empty()){
        int floor = q.front().first;
        int num = q.front().second;
        q.pop();
        if(floor == G){
            cout << num << "\n";
            return;
        }
        int next = floor + U;
        if(next <= F && !check[next]){
            check[next] = true;
            q.push(make_pair(next, num + 1));
        }
        next = floor - D;
        if(next > 0 && !check[next]){
            check[next] = true;
            q.push(make_pair(next, num + 1));
        }
    }

    cout << "use the stairs\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(check, false, sizeof(check));
    cin >> F >> S >> G >> U >> D;
    bfs();
}