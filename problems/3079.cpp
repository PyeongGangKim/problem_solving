#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> checkPerson;
long long N, M;

long long cal(long long mid){
    long long sum = 0;
    for(int i = 0 ; i < N ; i++){
        sum += mid/checkPerson[i];
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin >> N >> M;
    long long maxVal = 0;
    checkPerson.resize(N);
    for(int i = 0 ; i < N ; i++){
        cin >> checkPerson[i];
        maxVal = max(maxVal, checkPerson[i]);
    }
    long long left = 0;
    long long right = maxVal * M;
    long long mid, sum;
    long long result = right;
    while(left <= right){
        mid = (left + right)/2;
        sum = cal(mid);
        if(sum >= M){
            result = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << result << "\n";


}