#include <iostream>

using namespace std;

#define INF 9999999999
typedef long long ll;
ll nums[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    int start = 0;
    int end = N-1;
    ll diff = INF;
    int num1; int num2;
    while(start < end){
        ll temp = nums[start] + nums[end];
        if(abs(temp) < abs(diff)){
            diff = temp;
            num1 = start;
            num2 = end;
        }
        if(temp < 0) start++;
        else if(temp > 0) end--;
        else break;
    }
    cout << nums[num1] << " " << nums[num2] << "\n";
}