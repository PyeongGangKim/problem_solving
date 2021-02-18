#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int INF = 1000000;
bool canUseNum[10] = {true, };


bool checkTrueNum(int num){
    while(1){
        if(canUseNum[num%10]) num /= 10;
        else return false;
        if(num == 0) break;
    }

    return true;
}

int cntNum(int wantedNum){
    int minNum = 987654321;
    for(int i = 0 ; i <= INF ; i++){
        if(checkTrueNum(i)){
            int temp = to_string(i).length();
            temp += abs(i - wantedNum);
            minNum = min(temp,minNum);
        }
    }
    return minNum;
}

int main(){
    int wrongBtn, temp;
    int wantedNum, onlyTwoBtn;
    cin >> wantedNum;
    cin >> wrongBtn;
    for(int i = 0 ; i < 10 ; i++){
        canUseNum[i] = true;
    }
    for(int i = 0 ; i < wrongBtn ; i++){
        cin >> temp;
        canUseNum[temp] = false;
    }
    onlyTwoBtn = abs(wantedNum - 100);
    int manyBtn = cntNum(wantedNum);
    cout << min(onlyTwoBtn, manyBtn) << "\n";
}