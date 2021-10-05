#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int cache[16];
vector<pair<int,int> > v;

int dp(int day){
    if(day >= N) return 0;
    int &res = cache[day];
    if(res != -1) return res;
    if(day + v[day].first <= N){
        res = dp(day + v[day].first) + v[day].second;
    }
    res = max(res, dp(day+1));

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i = 0 ; i < N ; i++){
        int day, money;
        cin >> day >> money;
        v.push_back(make_pair(day,money));
    }
    cout << dp(0) << "\n";
}