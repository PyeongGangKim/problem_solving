#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> pq;
    vector<pair<int, int> > v;
    vector<int> v_bag;
    int N, K;
    cin >> N >> K;
    int temp_weight, temp_value;
    for(int i = 0 ; i < N ; i++){
        cin >> temp_weight >> temp_value;
        v.push_back(make_pair(temp_weight, temp_value));
    }
    for(int i = 0 ; i < K ; i++){
        cin >> temp_weight;
        v_bag.push_back(temp_weight);
    }
    sort(v.begin(), v.end(), cmp);
    sort(v_bag.begin(), v_bag.end());
    int idx = 0;
    long long result = 0;
    for(int i = 0 ; i < K ; i++){
        while(idx < N && v[idx].first <= v_bag[i]){
            pq.push(v[idx].second);
            idx++;
        }
        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << "\n";
}