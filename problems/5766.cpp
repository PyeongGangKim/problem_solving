#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    while(1){
        unordered_map<int,int> m;
        vector<pair<int,int> > v;
        cin >> N >> M;
        if(N == 0 || M == 0) break;
        int num;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cin >> num;
                if(m.find(num) != m.end()){
                    m[num]++;
                }
                else{
                    m[num] = 1;
                }
            }
        }
        for(auto elem : m){
            v.push_back(make_pair(elem.second, elem.first));
        }
        sort(v.begin(), v.end(), cmp);
        int first = v[0].first;
        int second = v[0].first;
        for(int i = 1 ; i < v.size() ; i++){
            if(second != first && second > v[i].first) break;
            if(first > v[i].first && second == first){
                second = v[i].first;
            }
            if(first > v[i].first && second != first){
                cout << v[i].second << " ";
            }
        }
            cout << "\n";

        
    }
}
