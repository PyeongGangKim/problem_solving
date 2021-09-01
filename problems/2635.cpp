#include <iostream>

using namespace std;

int N;

int cal(int n, bool isPrint){
    int next = N - n;
    int cur = n;
    int prev = n;
    int cnt = 2;
    while(next >= 0){
        cnt++;
        cur = next;
        if(isPrint) cout << cur << " ";
        next = prev - cur;
        prev = cur;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    cin >> N;
    int num = 2;
    int res = 0;
    int temp;
    for(int i = N/2 ; i <= N ; i++){
        temp = cal(i,false);
        if(num < temp){
            num =  temp;
            res = i;
        }
    }
    cout << num << "\n";
    cout << N << " " << res << " ";
    cal(res, true);
}