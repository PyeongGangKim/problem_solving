#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i = 1 ; i <= N ; i++){
        v.push_back(i);
    }
    M = M -1;
    int cursor = M;
    int vectorSize = v.size();
    cout << "<"; 
    while(vectorSize != 1){
        
        cout << v[cursor] << ", ";
        v.erase(v.begin() + cursor);
        cursor += M;
        vectorSize--;
        while(cursor >= vectorSize){
            cursor -= vectorSize;
        }
    }
    cout << v[0] << ">";
}