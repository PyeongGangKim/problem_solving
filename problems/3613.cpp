#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int diff = 'a' - 'A';

    string str;
    cin >> str;
    string res = "";
    bool isError = false;
    bool isBefor_ = false;
    bool isJava = false;
    bool isC = false;
    // C++ 인데 java인 경우
    // 대문자가 나오면 java, _가 나오면 C++
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            if(isC){
                isError = true;
                break;
            }
            isJava = true;
            res += '_';
            res += (char)(str[i] + diff);
        }
        else if(str[i] == '_'){
            if(isJava){
                isError = true;
                break;
            }
            if(isBefor_){
                isError = true;
                break;
            }
            isC = true;
            isBefor_ = true;
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            if(isBefor_){
                res += (char)(str[i] - diff);
            }
            else{
                res += str[i];
            }
            isBefor_ = false;
        }
        else{
            isError = true;
            break;
        }
    }
    if(str[0] >= 'A' && str[0] <= 'Z') isError = true;
    if(str[0] == '_' || str[str.size() - 1] == '_') isError = true;
    if(isError) cout << "Error!\n";
    else cout << res << "\n";
}