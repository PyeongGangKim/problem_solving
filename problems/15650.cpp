#include <iostream>
#include <vector>

using namespace std;

int M;
int N;
bool check[9];
vector<int> v;
void print(){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
void backTracking(int n, int cnt){
    if(cnt == M){
        print();
    }
    for(int i = n ; i <= N ; i++){
        if(check[i]) continue;
        check[i] = true;
        cnt++;
        v.push_back(i);
        backTracking(i+1, cnt);
        v.pop_back();
        cnt--;
        check[i] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backTracking(1,0);

}