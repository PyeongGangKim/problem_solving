#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b){
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int LCM(int a, int b){
    return a*b/GCD(a,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int num1, num2;
    cin >> num1 >> num2;
    int minNum = min(num1,num2);
    int maxNum = max(num1,num2);
    cout << GCD(maxNum,minNum) << "\n";
    cout << LCM(maxNum, minNum) << "\n";
}