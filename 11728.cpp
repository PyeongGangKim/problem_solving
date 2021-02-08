#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b;
    cin >> a >> b;
    vector<int> A;
    
    for(int i = 0 ; i < a+b ; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(), A.end());
    for(int i = 0 ; i < a+b ; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}