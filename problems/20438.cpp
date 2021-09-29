#include <iostream>
#include <cstring>

#define MAX 5004

using namespace std;

int N,K,Q,M;

int sum[MAX];

bool isSleep[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> Q >> M;

    memset(isSleep, false, sizeof(isSleep));
    memset(sum, 0, sizeof(sum));

    for(int i = 0 ; i < K ; i++){  
        int std;
        cin >> std;
        isSleep[std] = true;
    }
    for(int i = 0 ; i < Q ; i++){
        int a;
        cin >> a;
        if(isSleep[a]) continue;
        for(int j = a ; j <= N + 2 ; j += a){
            if(isSleep[j]) continue;
            sum[j] = 1;
        }
    }
    sum[2] = 0;
    for(int i = 4 ; i <= N + 2 ; i++){
        sum[i] += sum[i-1];
    }
    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;
        cout << (b - a + 1) - (sum[b] - sum[a-1]) << "\n";
    }
}