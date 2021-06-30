#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
long long cal(long long time, vector<int> times){
    long long temp = 0;
    for(long long i = 0 ; i < times.size() ; i++){
        temp += time / times[i];
    }
    return temp;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)times[times.size() - 1] * n;
    long long temp = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        
        temp = cal(mid, times);
        cout << mid << " " << temp << "\n";
        if(temp >n)right = mid - 1;
        else if(temp < n) left = mid + 1;
        else{
            answer = mid;
            right = mid - 1;
        }
       
        
    }
    return answer;
}