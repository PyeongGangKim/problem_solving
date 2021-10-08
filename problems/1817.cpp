#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int res = 0;
    int N,M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0 ; i < N ; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int end = v.size() - 1;
    int start = 0;
    int sum = 0;
   for (int i = N - 1; i >= 0; i--) {
		sum += v[i];
		if (sum > M) {
			res++;
			sum = v[i];
		}
	}
    cout << res << "\n";
}