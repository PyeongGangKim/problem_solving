#include <iostream>
#include <string>

using namespace std;
long long cache[5001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string str;
    cin >> str;
    str = "0" + str;
    cache[0] = 1;
    
    
    for(int i = 1 ; i <= str.length() ; i++){
        if(str[i] - '0' > 0 && str[i] - '0' <= 9){
            cache[i] += cache[i-1] ;
            cache[i] %= 1000000; 
        }
        int num = (str[i-1] -'0') * 10 + (str[i] - '0');
        if(num >= 10 && num <= 26){
            cache[i] += cache[i-2];
            cache[i] %= 1000000; 
        }

    }
    if(str.length() == 1 && str[0] == 1){
        cout << '0' << "\n";
        return 0;
    }
    cout << cache[str.length() - 1] << "\n";
}