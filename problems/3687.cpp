#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    string small[101];
    string big[101];
    small[2] = "1"; small[3] = "7"; small[4] = "4"; small[5] = "2"; small[6] = "0"; small[7] = "8";
    big[2] = "1"; big[3] = "7"; big[4] = "11" ; big[5] = "71"; big[6] = "111"; big[7] = "711";
    for(int i = 8 ; i <= 100 ; i++){
        small[i] = small[2] + small[i-2];
        big[i] = big[i-2] + "1";
        for(int j = 3 ; j < i-1; j++){
            string temp = "";
            if(j == 6) temp = "6" + small[i-6];
            else temp = small[j] + small[i-j];
            if(temp.length() < small[i].length() ) small[i] = temp;
            else if(temp.length() == small[i].length()) small[i] = (temp < small[i]) ? temp : small[i];
            // cout << temp << " " << small[i] << "\n";
        }
        // cout << i << " " << small[i] << "\n";
    }
    
    while(tc--){
        int num;
        cin >> num;
        string bigNum = big[num];
        string smallNum = small[num];
        smallNum = (num == 6) ? "6" : small[num];
        cout << smallNum << " " << bigNum << "\n";
    }
}