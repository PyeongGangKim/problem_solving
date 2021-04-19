#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
float M;
int cal[5001];
int money[5001];
int cache[10001];

int dp(){
    int maxCal = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = money[i] ; j <= m ; j++){
            cache[j] = max(cache[j], cache[j-money[i]] + cal[i]);
            maxCal = max(maxCal, cache[j]);
        }
        
    }
    return maxCal;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    float temp_money;
    while(1){
        cin >> n >> M;
        if(n==0) break;
        m = M*100;
        memset(cal, 0, sizeof(cal));
        memset(money, 0, sizeof(money));
        memset(cache, 0, sizeof(cache));
        for(int i = 0 ; i < n ; i++){
            cin >> cal[i] >> temp_money;
            money[i] = temp_money*100;
        }
        cout << dp() << "\n";
    }
}