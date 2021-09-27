#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int mod = 1e9+9;
ll cache[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    
    int n,m;
    cin >> tc;
    cache[1][1] = 1;
    cache[2][1] = 1; cache[2][2] = 1;
    cache[3][1] = 1; cache[3][2] = 2; cache[3][3] = 1;
    for(int i = 4 ; i < 1001 ; i++){
        for(int j = 2 ; j <= i ; j++){
            cache[i][j] = ((cache[i-1][j-1] + cache[i-2][j-1]) % mod + cache[i-3][j-1]) % mod;
        }
    }
    for(int i = 0 ; i < tc ; i++){
        cin >> n >> m;
        ll res = 0;
        for(int j = 1 ; j <= m ; j++){
            res = (res + cache[n][j]) % mod;
        }
        cout << res << "\n";
    }
    
}