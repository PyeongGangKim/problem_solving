#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> >identity(5, vector<int>(5));


int squareSize;

vector<vector<int> > calc(vector<vector<int> > &a, vector<vector<int> > &b){
    vector<vector<int> > temp(squareSize, vector<int>(squareSize));
    for(int i = 0 ; i < squareSize ; i++){
        for(int j = 0 ; j < squareSize ; j++){
            for(int k = 0 ; k < squareSize ; k++){
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000;
        }
    }
    return temp;
}

vector<vector<int> > divide(vector<vector<int> > &a, long long n){
    if(n == 0) return identity;
    if(n%2 != 0) {
        vector<vector<int> > temp = divide(a,n-1);
        return calc(temp, a);
    }
    else{
        vector<vector<int> > half = divide(a, n/2);
        return calc(half, half);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    long long num;

    cin >> squareSize >> num;
    vector<vector<int> > initSquare(squareSize, vector<int>(squareSize));
    for(int i = 0 ; i < squareSize ; i++){
        for(int j = 0 ; j < squareSize ; j++){
            cin >> initSquare[i][j];
        }
        identity[i][i] = 1;
    }

    vector<vector<int> > result = divide(initSquare, num);
    for(int i = 0 ; i < squareSize ; i++){
        for(int j = 0 ; j < squareSize ; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
}