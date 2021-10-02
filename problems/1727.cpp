#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;
typedef long long ll;
int m_num, w_num;
int m[1001];
int w[1001];
ll cache[1001][1001];



void solve(){
    for(int i = 1; i <= m_num ; i++){
        for(int j = 1 ; j <= w_num ; j++){
            if(i == j) cache[i][j] = cache[i-1][j-1] + abs(m[i] - w[j]);
            else if(i > j) cache[i][j] = min(cache[i-1][j-1] + abs(m[i] - w[j]),cache[i-1][j]);
            else cache[i][j] = min(cache[i-1][j-1] + abs(m[i] - w[j]),cache[i][j-1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m_num >> w_num;
    int num;
    for(int i = 1 ; i <= m_num ; i++){
        cin >> m[i];
    }
    for(int i = 1 ; i <= w_num ; i++){
        cin >> w[i];
    }
    
    sort(m + 1, m+1+m_num);
    sort(w+1, w+1+w_num);
    solve();
    cout << cache[m_num][w_num] << "\n";
}