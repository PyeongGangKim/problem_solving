#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> v;
    for(int i = 0 ; i < N ; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<int>());
    long long res = 0;
    for(int i = 0 ; i < N ; i++){
        long long temp = v[i] - (i+1-1);
        if(temp < 0) temp = 0;
        res += temp;
    }
    cout << res << "\n";
}