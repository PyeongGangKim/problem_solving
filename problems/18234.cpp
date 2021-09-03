#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b ){
    if(a.first < b.first) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N,T;
    cin >> N >> T ;
    vector<pair<ll,ll> > v;

    ll cur, incr;
    for(ll i = 0 ; i < N ; i++){
        cin >> cur >> incr;
        v.push_back(make_pair(incr, cur));
    }
    sort(v.begin(), v.end(), cmp);
    ll s = T - N;
    ll res = 0;
    ll v_cnt = 0;
    for(ll i = s ; i < T ; i++){
        pair<ll, ll> temp = v[v_cnt++];
        res += temp.first * i + temp.second;
    }
    cout << res << "\n";
}