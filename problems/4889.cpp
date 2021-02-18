#include <iostream>
#include <vector>
#include <string>

using namespace std;

int bracketChange(string str){
    vector<char> brackets;
    int count = 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '{') brackets.push_back(str[i]);
        else{
            if(brackets.empty()) {
                brackets.push_back('}');
                count++;
            }
            else brackets.pop_back();
        }
    }
    if(!brackets.empty()) return count + (brackets.size() / 2);
    return count;
}

int main(){
    string str;
    int countNum = 0;
    int changeNum;
    while(1){
        cin >> str;
        if(str[0] == '-') break;
        countNum++;
        changeNum = bracketChange(str);
        cout << countNum << ". " << changeNum << "\n";
    }
}