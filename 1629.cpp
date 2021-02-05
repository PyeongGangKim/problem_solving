#include <iostream>

using namespace std;



long long pow(long long a, long long b, long long c){
    if(b == 0) return 1;
    if(b == 1) return a % c;
    if(b%2 == 0) {
        long long temp = pow(a, b/2, c);
        return temp * temp % c;
    }
    else{
        return pow(a, b-1, c) * pow(a, 1, c) % c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << pow(A, B, C) << "\n";
}