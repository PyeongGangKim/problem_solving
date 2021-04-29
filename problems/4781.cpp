#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
float M;

vector<pair<int, int > > v;
int cache[10001];

int dp(){
    int maxCal = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = v[i].second ; j <= m ; j++){
            cache[j] = max(cache[j], cache[j-v[i].second] + v[i].first);
            maxCal = max(maxCal, cache[j]);
        }
        
    }
    return maxCal;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    float temp_money;
    int temp_cal;
    while(1){
        cin >> n >> M;
        if(n==0 && M == 0) break;
        m = M*100;
        
        v.clear();
        memset(cache, 0, sizeof(cache));
        for(int i = 0 ; i < n ; i++){
            cin >> temp_cal >> temp_money;
            v.push_back(make_pair(temp_cal, (int)temp_money*100));
        }
        sort(v.begin(), v.end());
        dp();
        cout <<  cache[m] << "\n";
    }
}