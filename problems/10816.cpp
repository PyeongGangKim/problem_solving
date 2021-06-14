#include <iostream>
#include <unordered_map>

using namespace std;
int target[500001];
int sanggeon[500001];
int targetNum, haveNum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    unordered_map<int, int> hashMap;

    cin >> haveNum;
    for(int i = 0 ; i < haveNum ; i++){
        cin >> sanggeon[i] ;
    }
    cin >> targetNum;
    for(int i = 0 ; i < targetNum ; i++){
        cin >> target[i];
        hashMap[target[i]] = 0;
    }
    for(int i = 0 ; i < haveNum ; i++){
        auto it = hashMap.find(sanggeon[i]);
        if(it != hashMap.end()){
            it->second = it->second + 1;
        }
    }
    for(int i = 0 ; i < targetNum ; i++){
        auto it = hashMap.find(target[i]);
        cout << it->second << " ";
    }
    
}