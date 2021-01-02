#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    vector<int> r_num;

    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        int temp;
        cin >> temp;
        r_num.push_back(temp);
    }
    sort(r_num.begin(),r_num.end());
    for(int i = 0 ; i < num ; i++){
        cout << r_num[i] << "\n";
    }
}