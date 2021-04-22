#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
int N;
bool check[8] = {false,};
vector<int> nums;
vector<int> v;
void print(){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
void backTracking( int cnt){

    if(cnt == M){
        print();
    }
    else{
        for(int i = 0 ; i < N ; i++){
            if(check[i]) continue;
            check[i] = true;
            cnt++;
            v.push_back(nums[i]);
            backTracking(cnt);
            v.pop_back();
            cnt--;
            check[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    backTracking(0);

}