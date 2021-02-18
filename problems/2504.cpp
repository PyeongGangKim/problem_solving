#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string input;
    cin >> input;
    vector<char> brackets;
    int result = 0;
    int temp = 1;
    bool wrongInput = false;
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == '('){
            brackets.push_back(input[i]);
            temp *= 2;
        }
        else if(input[i] == '['){
            brackets.push_back(input[i]);
            temp *= 3;
        }
        else if(input[i] == ')'){
            if(brackets.empty() || brackets.back() != '(' ){
                wrongInput = true;
                break;
            }
            else{
                if(input[i-1] == '('){
                    result += temp;
                }
                brackets.pop_back();
                temp /= 2;
            }
        }
        else if(input[i] == ']'){
            if(brackets.empty() || brackets.back() != '[' ){
                wrongInput = true;
                break;
            }
            else{
                if(input[i-1] == '['){
                    result += temp;
                }
                brackets.pop_back();
                temp /= 3;
            }
        }
    }
    if(wrongInput | !brackets.empty()) cout << '0' << '\n';
    else cout << result << '\n';
}