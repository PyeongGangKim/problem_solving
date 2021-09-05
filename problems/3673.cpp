#include <iostream>
#include <cstring>

#define MAX 1000000

typedef long long ll;

using namespace std;
int n,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    ll mod[MAX];
    for(int i = 0 ; i < tc ; i++){
        ll sum = 0;
        ll temp;
        memset(mod, 0, sizeof(mod));
        cin >> d >> n;
        for(int j = 0 ; j < n ; j++){
            cin >> temp;
            sum += temp;
            sum = sum % d;
            mod[sum]++;
        }
        ll res = mod[0];
        for(int j = 0 ; j < d ; j++){

            res += mod[j] * (mod[j] - 1) / 2; //nC2
        }
        cout << res << "\n";
    }

}