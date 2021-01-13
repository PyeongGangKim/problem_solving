#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int alpha[26] = {0,};
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        alpha[str[i] - 'a']++;
    }
    for(int i = 0; i < 26 ; i++){
        cout << alpha[i] << " ";
    }
}
