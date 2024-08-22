#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	
	cin >> n;
	
	int dp[n + 1];
	
	// dp[0] = 0;
	dp[1] = 3;
	dp[2] = 7;
	
	for (int i = 3; i < n + 1; i++) {
		dp[i] = (2*dp[i-1] + dp[i-2]) % 9901;
	}
	
	cout << dp[n];	
	
}
