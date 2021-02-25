#include <iostream>
#include <vector>
#include <string>

using namespace std;

void operate(string str){
    vector<char> st;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '/' || str[i] == '*'){
            while(!st.empty() && (st.back() == '/' || st.back() == '*')){
                cout << st.back();
                st.pop_back();
            }
            st.push_back(str[i]);
        }
        else if(str[i] == '-' || str[i] == '+'){
            while(!st.empty() && st.back() != '('){
                cout << st.back();
                st.pop_back();
            }
            st.push_back(str[i]);
        }
        else if(str[i] == '('){
            st.push_back(str[i]);
        }
        else if(str[i] == ')'){
            while(st.back() != '('){
                cout << st.back();
                st.pop_back();
            }
            st.pop_back();
        }
        else cout << str[i];
    }
    while(!st.empty()){
        cout << st.back();
        st.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str;
    cin >> str;
    operate(str);
}