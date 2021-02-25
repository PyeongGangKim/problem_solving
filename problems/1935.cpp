#include <iostream>
#include <stack>
#include <string>

using namespace std;
int alphabetNum[26];
stack<double> st;

double operate(string str){
    double n1, n2;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            st.push(alphabetNum[str[i] - 'A']);
        }
        else{
            n1 = st.top(); st.pop();
            n2 = st.top(); st.pop();
            if(str[i] == '+'){
                st.push(n2 + n1);
            }
            else if(str[i] == '-'){
                st.push(n2 - n1);
            }
            else if(str[i] == '*'){
                st.push(n2 * n1);
            }
            else{
                st.push(n2 / n1);
            }
        }
    }
    return st.top();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    int num;
    string str;
    cin >> num;
    cin >> str;
    for(int i = 0 ; i < num ; i++){
        cin >> alphabetNum[i];
    }
    printf("%.2lf", operate(str));
}