#include <iostream>
#include <cstring>

using namespace std;

int N;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if(N%2 == 1) cout << "SK\n";
    else cout <<"CY\n";
}