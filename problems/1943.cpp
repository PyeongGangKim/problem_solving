#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> v;
    while(cin >> N){
        int p1 = 0; int p2 = 0;
        while(N--){
            int coin, num;
            cin >> coin >> num;
            while(num--) v.push_back(coin);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0 ; i < v.size() ; i++){
            if(p1 <= p2){
                p1 += v[i];
            }
            else p2 += v[i];
        }
        v.clear();
        // cout << p1 << " " << p2 << "\n";
        if(p1 == p2) cout << "1\n";
        else cout << "0\n";
    }
}