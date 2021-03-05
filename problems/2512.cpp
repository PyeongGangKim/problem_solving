#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> country;
long long N, M;
long long calculate(long long value){
    long long sum = 0;
    for(long long i = 0 ; i < N ; i++){
        sum += min(country[i], value);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    long long temp;
    long long low = 0;
    long long high;
    for(long long i = 0 ; i < N ; i++){
        cin >> temp;
        country.push_back(temp);
        
        high = max(high, temp);
    }
    cin >> M;
    long long mid;
    long long result = 0;
    long long sum = 0;
    while(low <= high){
        mid = (high + low) / 2;
        sum = calculate(mid);
        if(sum <= M){
            result = max(result , mid);
            low = mid + 1;
        }
        else high = mid - 1;

    }
    cout << result << "\n";

}