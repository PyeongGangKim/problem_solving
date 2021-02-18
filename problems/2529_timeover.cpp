#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;
bool check_true_num(string number, string symbol, int len){
    bool check = true;
    for(int j = 0 ; j < len ; j++){
        if(symbol[j] == '>'){
            if(number[j] > number[j+1]) check = true;
            else {
                check = false;
                break;
           }
        }
        else if(symbol[j] == '<'){
            if(number[j] < number[j+1]) check = true;
            else {
                check = false;
                break;
            }
        }
    }
    return check;
}

bool check_same_num(string number){
    for(int i = 0; i < number.length(); i++){
        for(int j = i+1; j < number.length(); j++){
            if(number[i] == number[j]) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num;
    scanf("%d",&num);
    string symbol;
    for(int i = 0; i < num; i++){
        cin >> symbol[i];
    }
    int max_num = 1;
    for(int i = 0; i <= num; i++){
        max_num = max_num*10;
    }
    for(int i = 1; i <= max_num; i++){
        bool check = true;
        string temp = to_string(i);
        if (temp.length() > num) temp = temp;
        else if(temp.length() == num) temp = "0" + temp;
        else continue;
        check = check_true_num(temp, symbol, num);
        if(!check) continue;
        check = check_same_num(temp);
        if(check) result.push_back(i);
    }
    sort(result.begin(),result.end());
    int ten = 1;
    int ten_check = result[0];
    while(1){
        ten_check = ten_check/10;
        if(ten_check == 0) break;
        ten++;
    }
    if(ten == num) printf("%d\n0%d\n",result.back(),result[0]);
    else printf("%d\n%d\n",result.back(),result[0]);
}