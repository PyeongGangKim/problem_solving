#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll N, K;
    ll quo, remain;
    ll cnt = 0;
    vector<ll> v;

    cin >> N >> K;
    for(ll i = 0 ; i < N ; i++){
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(ll i = N-1 ; i >= 0; i--){
        quo = K / v[i];
        remain = K % v[i];
        if(quo != 0){
            cnt += quo;
            K = remain;
        }
        if(remain == 0) break;
    }
    cout << cnt << "\n";
}