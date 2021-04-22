#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int M;
int N;
bool check[8] = {false,};
int temp[8];
vector<int> nums;
vector<int> v;
set<vector<int> > result;


void put(){
    vector<int> temp_v;
    for(int i = 0 ; i < M ; i++){
        temp_v.push_back(temp[i]);
    }
    result.insert(temp_v);
    temp_v.clear();
}
void backTracking( int cnt){

    if(cnt == M){
        put();
    }
    else{
        for(int i = 0 ; i < N ; i++){
            temp[cnt] = nums[i];
            backTracking(cnt+1);
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
    for(auto a : result){
        for(int i = 0 ; i < a.size() ; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

}