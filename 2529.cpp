#include <iostream>
#include <vector>

using namespace std;

vector<string> result;
vector<int> check_num;
bool check[10];
string symbol;
int num;
bool check_true_number(){
    for(int i = 0 ; i < num ; i++){
        if(symbol[i] == '<'){
            if(!(check_num[i] < check_num[i+1])) return false;
        }
        else{
            if(!(check_num[i] > check_num[i+1])) return false;
        }
    }
    return true;
}
string make_num_str(){
    string result_str = "";
    for(int i = 0 ; i < num + 1 ; i++){
        result_str += to_string(check_num.at(i));
    }
    return result_str;
}
void dfs(int count){
    if(count == num+1){
        if(check_true_number()){
            string result_str = make_num_str();
            result.push_back(result_str);
        } 
    }
    else{
        for(int i = 0; i <= 9 ; i++){
            if(!check[i]){
                check_num.push_back(i);
                check[i] = true;
                dfs(count+1);
                check[check_num.back()] = false;
                check_num.pop_back();
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> symbol[i];
    }
    dfs(0);
    cout << result.back() << endl;
    cout << result.front() << endl;

}