#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long X, Y;
    cin >> X >> Y;
    int cur = (Y*100) / X;
    int next;

    if(cur>=99){
        cout << "-1" << "\n";
        return 0;
    }
    int low = 0;
    int high = 1000000000;
    int result = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        next = (Y+mid)*100 / (X+mid);
        if(cur >= next){
            low = mid+1;
            result = mid+1;
        }
        else{
            high = mid-1;
        }
        
    } 
    cout << result << "\n";
}