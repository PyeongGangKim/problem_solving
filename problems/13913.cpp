#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>

#define MAX 100001

using namespace std;

bool check[MAX];
int parent[MAX];

int N,K;

stack<int> res;
int res_num;

void bfs(){
    //먼저 N을 넣기.
    queue<pair<int, int> > q;
    q.push(make_pair(N,0));
    parent[N] = N;
    check[N] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int num = q.front().second;
        q.pop();
        if(cur == K){
            while(parent[cur] != cur){
                //stack에 cur을 넣고, cur = parent[cur];
                res.push(cur);
                cur = parent[cur];
            }
            res.push(cur);
            res_num = num;
            break;
        }
        //next 3개 cur+1 cur-1 cur*2
        int next_1 = cur + 1; int next_2 = cur - 1 ; int next_3 = cur * 2;
        if(next_1 >= 0 && next_1 <= MAX-1 && !check[next_1]){
            q.push(make_pair(next_1,num+1));
            parent[next_1] = cur;
            check[next_1] = true;
        }
        if(next_2 >= 0 && next_2 <= MAX-1 && !check[next_2]){
            q.push(make_pair(next_2,num+1));
            parent[next_2] = cur;
            check[next_2] = true;
        } 
        if(next_3 >= 0 && next_3 <= MAX-1 && !check[next_3]){
            q.push(make_pair(next_3,num+1));
            parent[next_3] = cur;
            check[next_3] = true;
        }  
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);

    cin >> N >> K;

    memset(check,false,sizeof(check));
    bfs();
    cout << res_num << "\n";
    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
}