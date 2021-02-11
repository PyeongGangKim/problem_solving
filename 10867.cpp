#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num, temp;;
    vector<int> v;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < num ; i++){
        if(i != 0 && v[i] == v[i-1]) continue;
        cout << v[i] << " ";
    }
    cout << "\n";
}