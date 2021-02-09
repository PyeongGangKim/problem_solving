#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num, tempNum;
    cin >> num;
    vector<int> stack;
    while(num--){
        char temp[10];
        cin >> temp;
        if(strcmp(temp, "push") == 0) {
            cin >> tempNum;
            stack.push_back(tempNum);
        }
        else if(strcmp(temp, "pop") == 0){
            if(stack.empty()) cout << "-1" << "\n";
            else{
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        }
        else if(strcmp(temp, "size") == 0) cout << stack.size() << "\n";
        else if(strcmp(temp, "empty") == 0){
            if(stack.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else{
            if(stack.empty()) cout << "-1" << "\n";
            else cout << stack.back() << "\n";
        }
    
    }
}