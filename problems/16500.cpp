#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;
	int N;
	string A[100];
	int dp[101];

	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dp[S.length()] = 1;

	for (int pos = S.length() - 1; pos >= 0; pos--) {
		for (int j = 0; j <= N; j++) {
			if (S.find(A[j], pos) == pos && dp[pos + A[j].length()] == 1) {
				dp[pos] = 1;
				break;
			}
			else {
				dp[pos] = 0;
			}
		}
	}

	cout << dp[0];
}