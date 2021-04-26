#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>



using namespace std;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<long long> v;
    long long temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int start = 0; int end = 1;
    long long num = v[start] - v[end];
    num = (num < 0) ? num * -1 : num;
    int idx = 0;
    while(end < N){
        long long curDiff = v[start] - v[end];
        curDiff = (curDiff < 0) ? curDiff * -1 : curDiff;
        if(curDiff < num){
            num = curDiff;
            idx = start;
        }
        if(num == 0) break;
        start++; end++;
    }
    cout << v[idx] << " " << v[idx+1] << "\n";
}