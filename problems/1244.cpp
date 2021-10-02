#include <iostream>
#include <cstring>

using namespace std;
int N;
bool switchBtn[101];
int stNum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int num;
        cin >> num;
        if(num == 0){
            switchBtn[i] = false;
        }
        else{
            switchBtn[i] = true;
        }
    }
    cin >> stNum;
    for(int i = 0 ; i < stNum ; i++){
        int s, num;
        cin >> s >> num;
        int plus = num;
        if(s == 1){
            while(num <= N){
                switchBtn[num] = !switchBtn[num];
                num += plus;
            }
        }
        else{
            int front = num;
            int back = num;
            while(1){
                if(front <= 0 || back > N) break;
                if(front == back) switchBtn[front] = !switchBtn[front];
                else{
                    if(switchBtn[front] == switchBtn[back]){
                        switchBtn[front] = !switchBtn[front];
                        switchBtn[back] = !switchBtn[back];
                    }
                    else break;
                }
                front--; back++;
            }
        }
    }
    for(int i = 1 ; i <= N ; i++){
        if(switchBtn[i]) cout << "1 ";
        else cout << "0 ";
        if(i%20 == 0) cout << "\n";
    }    
}