#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a ,pair<int, int>b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    
    vector<pair<int,int> > p;
    int n1, n2;
    for(int i = 0; i < n; i++){
        cin >> n1>> n2;
        p.push_back(make_pair(n1,n2));
    }
    sort(p.begin(),p.end(), compare);

    for(int i = 0; i < n; i++){
        cout << p[i].first << " " << p[i].second << "\n";
    }

}