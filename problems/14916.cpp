#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100001

using namespace std;

int coin[MAX];
int N;

int dp(int n){
    int &res = coin[n];
    if(res != -1) return res;
    res = min(dp(n - 2) + dp(2), dp(n-5) + dp(5));
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(coin, -1, sizeof(coin));

    coin[1] = MAX; coin[0] = MAX; coin[2] = 1; coin[3] = MAX; coin[5] = 1; coin[4] = 2;
    dp(N);
    if(coin[N] >= MAX) cout << "-1\n";
    else cout << coin[N] << "\n";
}