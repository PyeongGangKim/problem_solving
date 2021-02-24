#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    int dp_min[1001];
    int dp_max[1001];
    int a[1001];

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp_min[i] = 1;
        dp_max[i] = 1;
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j]) dp_max[i] = max(dp_max[j] + 1, dp_max[i]); 
        }
    }

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j > i ; j--){
            if(a[i] > a[j]) dp_min[i] = max(dp_min[j] + 1, dp_min[i]);
        }
    }
    for(int i = 0 ; i < n ; i++){
        ans = max(ans, dp_min[i] + dp_max[i] - 1);
    }
    cout << ans << "\n";
}