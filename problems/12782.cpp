#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;

    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> str1 >> str2;
        int size = str1.length();
        int str1One = 0;
        int str1Zero = 0;
        for(int j = 0 ; j < size ; j++){
            if(str1[j] != str2[j]){
                if(str1[j] == '1') str1One++;
                else str1Zero++;
            }
        }
        int res = (str1One > str1Zero) ? str1One : str1Zero;
        cout << res << "\n";
    }
}