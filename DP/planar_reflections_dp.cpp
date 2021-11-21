#include<bits/stdc++.h>
using namespace std;

// N planes, K decay age

int dp[1005][1005];

int main() {
    int n, k;
    cin >> n >> k;

    for(int decay = 1; decay <= k; decay++) {
        dp[decay][0] = 1;
        for(int planes = 1; planes <= n; planes++) {
            dp[decay][planes] = dp[decay - 1][n - planes] + dp[decay][planes - 1];
        }
    }
    cout << dp[k][n] << "\n";

    for(int i = 0; i <= k; i++) {
    	for(int j = 0; j <= n; j++) {
    		cout << dp[i][j] << " ";
    	}
    	cout << "\n";
    }
    cout << "----------" << "\n";
}