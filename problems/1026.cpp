#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i , int j){
    return j < i ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int A[51];
    int B[51];
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < num ; i++){
        cin >> B[i];
    }
    sort(A, A+num);
    sort(B, B+num, compare);
    int result = 0;
    for(int i = 0 ; i < num ; i++){
        result += A[i] * B[i];
    }
    cout << result << "\n";
}