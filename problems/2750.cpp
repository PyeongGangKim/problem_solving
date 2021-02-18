#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    
    cin >> num;
    vector<int> n(num);
    for(int i = 0 ; i < num ; i++){
        cin >> n[i];
    }
    sort(n.begin(),n.end());
    for(int i = 0 ; i < num ; i++){
        cout << n[i] << "\n";
    }
}