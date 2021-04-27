#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

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
    int start = 0; int end = N - 1;
    long long minNum = v[start] + v[end];
    int lIdx = start ; int rIdx = end;

    while(start < end){
        long long curDiff = v[start] + v[end];
        if(abs(curDiff) < abs(minNum)){
            minNum = curDiff;
            lIdx = start;
            rIdx = end;
        }
        if(curDiff <= 0) start++;
        else end--;
    }
    cout << v[lIdx] << " " << v[rIdx] << "\n";
}