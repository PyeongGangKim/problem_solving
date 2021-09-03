#include <iostream>

using namespace std;

int map[4][4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M; // 세로, 가로
    cin >> N >> M;
    string str;
    for(int i = 0 ; i < N ; i++){
        cin >> str;
        for(int j = 0 ; j < M ; j++){
            map[i][j] = str[j] - '0';
            // cout << map[i][j] << " "; 
        }
    }
    //총 경우의 수 i << m*n
    int res = 0;
    for(int b = 0 ; b < (1 << (M*N)) ; b++){
        int sum = 0;
        for(int i = 0 ; i < N ; i++){
            int now = 0;
            for(int j = 0 ; j < M ; j++){
                int cur = i * M + j; //일렬로 나타내기
                if((b & (1 << cur)) == 0){ //현재 숫자가 가로일 경우
                    now = now * 10 + map[i][j];
                    // cout << now << "\n";
                }
                else{
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
            // cout << now << "\n";
        }
        for(int j = 0 ; j < M ; j++){
            int now = 0;
            for(int i = 0 ; i < N ; i++){
                int cur = i * M + j; //일렬로 나타내기
                if((b & (1 << cur)) != 0){ //현재 숫자가 가로일 경우
                    now = now * 10 + map[i][j];
                }
                else{
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }
        res = max(res, sum);
    }
    cout << res << "\n";
}