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
    sort(v.begin(), v.end());
    int start = 0;
    int end = v.size() - 1;
    int res = 0;
    while(start < end){
        res += v[end] * 2;
        start++; end--;
    }
    if(start == end){
        res += v[end];
    }
    cout << res << "\n";
}