#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> nums;
bool check[21] = {false,};
int result = 0;

void dfs(int i, int sum){
    if(i == N) return;
    if(sum + nums[i] == S) result++;

    dfs(i+1 , sum);
    dfs(i+1, sum + nums[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

     
    cin >> N >> S;
    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        nums.push_back(temp);

    }
    dfs(0,0);
    cout << result;
}