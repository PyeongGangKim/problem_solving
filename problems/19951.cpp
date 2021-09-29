#include <iostream>

#define MAX 100001

using namespace std;

int N,M;

int H[MAX];
int cSum[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1 ; i <= N ; i++){
        cin >> H[i];
    }
    for(int i = 0 ; i < M ; i++){
        int a,b,k;
        cin >> a >> b >> k;
        cSum[a] += k; cSum[b+1] -= k;
    }
    int sum = 0;
    for(int i = 1 ; i <= N ; i++){
        sum += cSum[i];
        cout << H[i] + sum << " ";
    }
    cout << "\n";
}
