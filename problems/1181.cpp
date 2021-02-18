#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    vector<string> v;
    int num;
    cin >> num;
    string temp;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0 ; i < num ; i++){
        if(i != 0 && v[i] == v[i-1]) continue;
        cout << v[i] << "\n";
    }
}