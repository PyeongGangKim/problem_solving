#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

#define DIV 1000000009

ll odd[100001];
ll even[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    int n;
    cin >> tc;
    odd[1] = 1; odd[2] = 1; odd[3] = 2; odd[4] = 3; odd[5] = 7;
    even[1] = 0; even[2] = 1; even[3] = 2; even[4] = 4; even[5] = 6;
    for(int i = 0 ; i < tc ; i++){
        cin >> n;
        for(int i = 4 ; i <= n ; i++){
            even[i] = (odd[i-3] + odd[i-2] + odd[i-1]) % DIV;
            odd[i] = (even[i-3] + even[i-2] + even[i-1]) % DIV;
        }
        cout << odd[n] << " " << even[n] << "\n";
    }
}