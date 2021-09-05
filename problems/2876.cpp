#include <iostream>
#include <cstring>

#define MAX 100001
using namespace std;

int N;
int cnt[6];
int maxCnt = 0, num = 6;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int num1, num2;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0 ; i < N ; i++){
        cin >> num1 >> num2;
        for(int j = 1 ; j < 6 ; j++){
            if(num1 == j || num2 == j){
                cnt[j]++;
                if(cnt[j] > maxCnt){
                    maxCnt = cnt[j];
                    num = j;
                }
                else if(cnt[j] == maxCnt){
                    if(num > j) num = j;
                }
            }else{
                cnt[j] = 0;
            }
        }
    }
    cout << maxCnt << " " << num << "\n";
}