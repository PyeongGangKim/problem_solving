#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 50001

using namespace std;


int n,T;
bool check[MAX];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second) return true;
    else return a.first < b.first;
}


vector<pair<int,int> > v;

int bfs(){
    queue<pair<int, pair<int, pair<int,int> > > > q;
    q.push(make_pair(0, make_pair(0,make_pair(0,0))));
    check[0] = true;
    while(!q.empty()){
        
        int num = q.front().first; int idx = q.front().second.first;
        int x = q.front().second.second.first; int y = q.front().second.second.second;
        q.pop();
        // cout << num << " " << idx << " " << x << " " << y << "\n";
        if(y == T) return num;
        for(int i = idx ; i <= n ; i++){
            if(check[i]) continue;
            int nX = v[i].first; int nY = v[i].second;
            //만약 현재 꺼와 3이상 차이나면 continue
            int diffX = (nX - x < 0) ? (nX - x)*-1 : nX -x;
            int diffY = (nY - y < 0) ? (nY - y)*-1 : nY -y;
            if(diffX > 2 || diffY > 2) continue;
            check[i] = true;
            q.push(make_pair(num+1,make_pair(i, make_pair(nX,nY))));
        }

        for(int i = idx ; i > 0 ; i--){
            if(check[i]) continue;
            int nX = v[i].first; int nY = v[i].second;
            //만약 현재 꺼와 3이상 차이나면 continue
            int diffX = (nX - x < 0) ? (nX - x)*-1 : nX -x;
            int diffY = (nY - y < 0) ? (nY - y)*-1 : nY -y;
            if(diffX > 2 || diffY > 2) continue;
            check[i] = true;
            q.push(make_pair(num+1,make_pair(i, make_pair(nX,nY))));
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> T;
    memset(check, false, sizeof(check));
    int x,y;
    for(int i = 0 ; i < 5 ; i++){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    v.push_back(make_pair(0,0));
    sort(v.begin(), v.end(), cmp);

    cout << bfs() << "\n";

}