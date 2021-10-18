#include <iostream>
#include <cstring>

#define MAX 1000001

typedef long long ll;

using namespace std;

int room[MAX];
int B,C,N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> room[i];
    }
    cin >> B >> C;
    ll res = 0;
    for(int i = 0 ; i < N ; i++){
        int temp = room[i] - B;
        if(temp <= 0) res += 1;
        else {
            res += (temp % C == 0) ? temp/C + 1 : temp/C + 2;
            
        }
    }
    cout << res << "\n";
}