#include <iostream>
#include <cstring>

using namespace std;

int N,M;

bool cache[2001][2001];


int gcd(int a, int b){
    
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(cache,false,sizeof(cache));

    cin >> N >> M;
    
    int sum = 0;
    for(int i = N ; i <= M ; i++){
        for(int j = 1 ; j <= i ; j++){
            int n = gcd(i,j);
            int a = j/n; int b = i/n;
            if(cache[a][b]) continue;
            cache[a][b] = true;
            sum++;
        }
        
    }

    cout << sum << "\n";

}