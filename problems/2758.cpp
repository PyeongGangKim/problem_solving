#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll cache[4002][11];

ll dp(int cnt, int num){
    if(cnt == 0) return 1;
    ll &res = cache[num][cnt];
    if(res != -1) return res;
    res = 0;
    // num은 선택한다고 가정
    for(int i = num / 2 ; i >= 1 ; i--){
        res += dp(cnt - 1, i);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    memset(cache, -1 ,sizeof(cache));
    while(tc--){
        int cnt,num;
        cin >> cnt >> num;
        cout << dp(cnt, num*2) << "\n";
    }
}