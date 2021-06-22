#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int maxNum = 1000000;
bool num[maxNum]; //소수 체크하는 배열
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int N;
    memset(num,false,sizeof(num));
    for(int i = 2 ; i <= maxNum ; i++){
        for(int j = i * 2 ; j <= maxNum ; j = j+i){
            num[j] = true;        
        }
    }
    while(1){
        cin >> N;
        bool result = false;
        if(N == 0) break;
        v.clear();
        for(int i = 2 ; i <= N ; i++){
            if(!num[i] && i % 2 == 1) v.push_back(i); 
        }

        for(int i = 0 ; i < v.size() ; i++){
            int a = v[i];
            int b = N - a;
            if(!num[b]){
                cout << N << " = " << a << " + " << b << "\n";
                break;
            }
            if(i == v.size() - 1) cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}