#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> nums;
vector<int> result;
bool check[13] = {false,};
void dfs(int n, int count){
    if(count == 6){
        for(int i = 0 ; i < 6 ; i++){
            cout << result[i] << " "; 
        }
        cout << "\n";
    }
    else{
        for(int i = n ; i < num ; i++){
            if(!check[i]){
                check[i] = true;
                result.push_back(nums[i]);
                dfs(i + 1, count + 1);
                check[i] = false;
                result.pop_back();
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int temp;
    while(1){
        cin >> num;
        if(num == 0) break;
        for(int i = 0 ; i < num ; i++){
            cin >> temp;
            nums.push_back(temp);
        }
        dfs(0,0);
        nums.clear();
        result.clear();
        cout << "\n";
    }
}