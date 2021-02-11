#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cache[101][101] = {-1,};

bool match(string wildcard, string str, int w, int s){
    int cW = w; int cS = s;
    
    if(cache[w][s] != -1) return cache[w][s];
    
    while(w < wildcard.length() && s < str.length() && wildcard[w] == str[s]){
        w++;
        s++;
    }

    if(w == wildcard.length()){
        if(s == str.length()) return cache[cW][cS] = 1;
        return cache[cW][cS] = 0;
    }
    if(wildcard[w] == '*'){
        for(int skip = 0 ; skip + s <= str.length() ; skip++){
            if(match(wildcard, str, w+1, s + skip)) return cache[cW][cS] = 1;
        }
    }
    return cache[cW][cS] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string temp, wildcard;
    cin >> wildcard;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> temp;
        memset(cache, -1, sizeof(cache));
        if(match(wildcard, temp, 0, 0)) cout << temp << "\n";
        
    }
}