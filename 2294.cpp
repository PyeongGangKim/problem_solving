#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> coin(n);
    vector<int> value(k+1, 987654321);

    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
        if(coin[i] > k) coin[i] = 0;
        else{
            value[coin[i]] = 1;
        }
    }
    for(int i = 1 ; i < k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i + coin[j] > k) continue;
            else{
                value[i+coin[j]] = min(value[i+coin[j]], value[i] + 1);
            }
            
        }
    }
    if(value[k] == 987654321) cout << "-1" << "\n";
    else cout << value[k] << "\n";

}