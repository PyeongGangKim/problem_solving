#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> result;
vector<int> check_symbol; // 여기 순서대로 symbols에 있는 거 빼서 쓰면 됨.  
bool check[10];
vector<int> symbols;// symbol들을 넣어 놓은 것,
vector<int> nums;//입력받은 숫자들
int num;

void cal(){
    int temp = 0;
    for(int i = 0 ; i < num - 1; i++){
        if(i == 0) temp = nums[i];
        if(symbols[check_symbol[i]] == 0){
            temp += nums[i+1];
        }
        else if(symbols[check_symbol[i]] == 1){
            temp -= nums[i+1];
        }
        else if(symbols[check_symbol[i]] == 2){
            temp *= nums[i+1];
        }
        else if(symbols[check_symbol[i]] == 3){
            temp /= nums[i+1];
        }
    }
    result.push_back(temp);
    
}

void dfs(int count){
    if(count == num-1){
        cal(); 
    }
    else{
        for(int i = 0; i < num - 1 ; i++){
            if(!check[i]){
                check_symbol.push_back(i);
                check[i] = true;
                dfs(count+1);
                check[check_symbol.back()] = false;
                check_symbol.pop_back();
            }
        }
    }
    return;
}
void make_symbol(int symbol_num[]){
    for(int i = 0 ; i < 4; i++){
        for(int j = 0 ; j < symbol_num[i] ; j++){
            symbols.push_back(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> num;
    int temp;
    int symbol_num[4] = {0,};
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    for(int i = 0 ; i < 4 ; i++){
        cin >> temp;
        symbol_num[i] = temp;
    }
    make_symbol(symbol_num);
    dfs(0);
    sort(result.begin(),result.end());
    cout << result.back() << "\n";
    cout << result.front() << "\n";

}