#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(int a, int b){
    return a > b;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string num;
    vector<int> result;
    cin >> num;
    for(int i = 0 ; i < num.length() ; i++){
        result.push_back((int)(num[i]) - (int)'0');
    }
    sort(result.begin(),result.end(), compare);
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
}