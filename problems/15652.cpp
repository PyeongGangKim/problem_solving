#include <iostream>
#include <vector>

using namespace std;

int M;
int N;

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
    else{
        for(int i = n ; i <= N ; i++){

            cnt++;
            v.push_back(i);
            backTracking(i, cnt);
            v.pop_back();
            cnt--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    backTracking(1,0);

}