#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int num;
int numbers[9];

bool checkNum[9] = {false, };
vector<int> formNum;
int maxFormResult = -1;
void checkForm(){
    int temp = 0;
    for(int i = 0 ; i < num - 1 ; i++){
        temp += abs(formNum[i] - formNum[i+1]);
    }
    maxFormResult = max(maxFormResult, temp);
}
void makeForm(){
    if(formNum.size() == num) checkForm();
    else{
        for(int i = 0 ; i < num ; i++){
            if(!checkNum[i]){
                formNum.push_back(numbers[i]);
                checkNum[i] = true;
                makeForm();
                checkNum[i] = false;
                formNum.pop_back();
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> numbers[i];
    }

    makeForm();
    cout << maxFormResult << "\n";
}