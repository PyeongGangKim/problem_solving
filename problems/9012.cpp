#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check(string temp){
    vector<char> stack;
    for(int i = 0 ; i < temp.length() ; i++){
        if(temp[i] == '(') stack.push_back(temp[i]);
        else{
            if(stack.empty()) return false;
            stack.pop_back();
        }
    }
    if(!stack.empty()) return false;

    return true;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string temp;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        if(check(temp)) cout << "YES" << "\n";
        else cout << "NO" << "\n"; 
    }
}