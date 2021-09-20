#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);   
    cin.tie(0);

    long long N, num1,num2;
    long long temp1, temp2;
    cin >> N;
    while(N--){
        cin >> num1 >> num2;
        temp1 = num1; temp2 = num2;
        while(temp1 != 0){
            if(temp1 < temp2){
                long long temp = temp1;
                temp1 = temp2;
                temp2 = temp;
            }
            temp1 %= temp2;
        }
        cout << (num1 * num2) / temp2 << "\n";
    }
}