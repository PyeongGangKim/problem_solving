#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    int res = 0;
    string temp;
    bool isMinus = false;
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == '+'){
            if(!isMinus){
                res += stoi(temp);
            }
            else{
                res -= stoi(temp);
            }
            temp = "";
        }
        else if(input[i] == '-'){
            if(!isMinus){
                res += stoi(temp);
            }
            else{
                res -= stoi(temp);
            }
            temp = "";
            isMinus = true;   
        }
        else temp += input[i];
    }

    if(!isMinus){
        res += stoi(temp);
    }
    else{
        res -= stoi(temp);
    }
    cout << res << "\n";
}