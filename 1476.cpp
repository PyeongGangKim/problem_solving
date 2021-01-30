#include <iostream>

using namespace std;

int resultE, resultS, resultM;

int year = 1;

bool checkResult(int e, int s, int m){
    if(e == resultE && s == resultS && m == resultM) return true;
    return false;
}

int countYear(int e, int s, int m){
    if(e > 15) e = 1;
    if(s > 28) s = 1;
    if(m > 19) m = 1;
    if(checkResult(e, s, m)) return year;
    year++;
    
    return countYear(e + 1, s + 1, m + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> resultE >> resultS >> resultM;

    cout << countYear(1,1,1) << "\n";
}