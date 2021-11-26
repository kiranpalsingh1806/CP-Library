
int coinChangeDP(vector<int>& a, int v, int n, vector<vector<int>>& dp) {
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {  // Either Pick this coin or not
        return dp[n][v] = coinChangeDP(a, v - a[n - 1], n, dp) + coinChangeDP(a, v, n - 1, dp);
    } else {   // We have no option but to leave this coin
    	return dp[n][v] = coinChangeDP(a, v, n - 1, dp);
    }     
}

void solve()
{
	int N, V;
    cin >> N >> V;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int> > dp(n + 1,vector<int>(v + 1, -1));
    cerr << lineSeparator() << "\n";
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= v; j++) {
    		cerr << dp[i][j] << " ";
    	}
    	cerr << "\n";
    }
    cerr << lineSeparator() << "\n";
    int res = coinChangeDP(a, v, n, dp);
    cout << res << endl;
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= v; j++) {
    		cerr << dp[i][j] << " ";
    	}
    	cerr << "\n";
    }
    cerr << lineSeparator() << "\n";
}

// Input
// 4 5
// 1 5 2 4
// Output
// 5

// Debugger
// ----------------------------------
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// -1 -1 -1 -1 -1 -1 
// ----------------------------------
// -1 -1 -1 -1 -1 -1 
// 1 1 1 1 1 1 
// 1 1 -1 1 -1 2 
// -1 1 -1 2 -1 4 
// -1 1 -1 -1 -1 5 
----------------------------------