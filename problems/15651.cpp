#include <iostream>
#include <vector>

using namespace std;

int M;
int N;
bool check[8];
vector<int> v;
void print(){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
void backTracking(int cnt){
    // cout << n << "\n";
    if(cnt == M){
        print();
    }
    else{
        for(int i = 1 ; i <= N ; i++){
            //if(check[i] && i != n) continue;
            // check[i] = true;
            cnt++;
            v.push_back(i);
            backTracking(cnt);
            v.pop_back();
            cnt--;
            // check[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backTracking(0);

}