#include <iostream>
#include <cstring>

using namespace std;
int N,M;
int nums[100001];
int sums[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        cin >> nums[i];
    }
    memset(sums,0,sizeof(sums));
    sums[1] = nums[1];
    for(int i = 2 ; i <= N ; i++){
        sums[i] += sums[i-1] + nums[i];
    }
    int start, end;
    while(M--){
        cin >> start >> end;
        cout << sums[end] - sums[start-1] << "\n";
    }
}