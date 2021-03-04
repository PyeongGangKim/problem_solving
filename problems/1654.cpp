#include <iostream>

using namespace std;

long long haveN, willHaveN;

bool isPossible(long long mid,long long *lan){
    long long cnt = 0;
    for(long long i = 0 ; i < haveN ; i++){
        cnt += lan[i]/mid;
    }
    if(cnt >= willHaveN) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long long low = 1;
    long long result = 0;
    long long high = 0;
    
    cin >> haveN >> willHaveN;
    long long lan[haveN];
    for(long long i = 0 ; i < haveN ; i++){
        cin >> lan[i];
        if(high < lan[i]) high = lan[i];
    }
    long long mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(isPossible(mid, lan)){
            if(result < mid){
                result = mid;
            }
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << result << "\n";
}