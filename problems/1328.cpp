#include<iostream>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;
ll cache[102][102][102];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, L, R;
    cin >> N >> L >> R;
    
    cache[1][1][1] = 1;
    for(int i = 2 ; i <= N ; i++){
        for(int j = 1 ; j <= L ; j++){
            for(int k = 1 ; k <= R ; k++){
                cache[i][j][k] = (cache[i-1][j-1][k] + cache[i-1][j][k-1] + cache[i-1][j][k] * (i-2)) % mod;
            }
        }
    }
    cout << cache[N][L][R] << "\n";
}