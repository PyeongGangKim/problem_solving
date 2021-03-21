#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a == b) return false;
    string ab = a+b;
    string ba = b+a;
    if(ab > ba) return true;
    else return false;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    vector<string> v;
    int num;
    cin >> num;
    v.resize(num);
    string temp;
    int flag = 0;
    for(int i = 0 ; i < num ; i++){
        cin >> v[i];
        if(v[i] != "0") flag = 1;
    }
    if(!flag){
        cout << "0";
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0 ; i < num ; i++){
        cout << v[i];
    }
    cout << "\n";
}