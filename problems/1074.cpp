#include <iostream>

using namespace std;



int N,r,c;
int cnt = 0;
int result;

int pow(int base, int num){
    if(num == 1) return base;
    else return base * pow(base, num - 1);
}
void divide(int x, int y, int n){
    if(r == y && c == x){
        result = cnt;
        return; 
    }
    if(r < y + n && r >= y && c < x + n && c >= x){
        divide(x, y, n/2);//왼위
        divide(x + n/2, y, n/2);//오위
        divide(x, y + n/2, n/2);//왼아
        divide(x + n/2, y + n/2, n/2);//오아
    }
    else{
        cnt += n * n;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> r >> c;
    divide(0, 0, pow(2, N));

    cout << result << "\n";
}