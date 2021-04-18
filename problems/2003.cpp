#include <iostream>

using namespace std;
int nums[10001];
int N,M;

int cal(int start, int end){
    int sum = 0;
    for(int i = start ; i <= end ; i++){
        sum += nums[i];
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin >> N >> M;
   
    int start,end;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    start = 0 ; end = 0;
    int checkNum;
    int cnt = 0;
    while(end < N){
        checkNum = cal(start, end);
        if(checkNum == M) {
            cnt++;
            end++;
            start++;
        }
        else if(checkNum < M){
            end++;
        }
        else{
            start++;
        }
        // cout << start << " " << end <<" "<< checkNum << "\n";
    }
    cout << cnt << "\n";

}