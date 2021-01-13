#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> stack;
vector<char> result;
int n;

void push(int start, int end){
    for(int i = start ; i <= end; i++){
        stack.push_back(i);
        result.push_back('+');
    }
}
void pop(){
    stack.pop_back();
    result.push_back('-');
}
void stackOperate(int start, int end){
    push(start, end);
    pop();
}
bool enu(){
    int temp;
    int cur_num = 1;
    for(int i = 0; i < n ; i++){
        temp = nums[i];
        if(stack.empty()){
            stackOperate(cur_num,temp);
            cur_num = temp + 1;
        }
        else{
            if(temp > stack.back()){
                stackOperate(cur_num,temp);
                cur_num = temp + 1;
            }
            else if(temp == stack.back()) pop();
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;

    int temp;
    for(int i = 0 ; i < n ; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    if(enu()){
        for(int i = 0 ; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }
    else{
        cout << "NO" << "\n";
    }

}