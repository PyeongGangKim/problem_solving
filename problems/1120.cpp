#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;
    int res = 1e9;
    int cnt = 0;
    while(A.length() + cnt <= B.length()){
        int temp_res = 0;
        for(int i = 0 ; i < A.length() ; i++){
            if(A[i] != B[i+cnt]) temp_res++;
        }
        cnt++;
        res = min(res, temp_res);
    }
    cout << res << "\n";
}