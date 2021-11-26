// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack01Rec(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W) {
    	return knapsack01Rec(W, wt, val, n - 1);
    } else {
		return max(
			val[n - 1] + knapsack01Rec(W - wt[n - 1], wt, val, n - 1),
			knapsack01Rec(W, wt, val, n - 1));
    }
}

int knapsack01DP(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    for(int i = 0; i < n + 1; i++) {
    	for(int j = 0; j < W + 1; j++) {
    		cerr << K[i][j] << " "; 
    	}
    	cerr << "\n";
    }
    return K[n][W];
}

int val[100005];
int wt[100005];

void solve()
{
	int n, W;
	cin >> n >> W;
	for(int i = 0; i < n; i++) {
		cin >> val[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> wt[i];
	}

    cout << knapsack01Rec(W, wt, val, n) << "\n";
    cout << knapsack01DP(W, wt, val, n) << "\n";
}

// Input
// 6 10
// 6 10 12 3 6 9
// 1 2 3 2 1 3

// Output
// 43
// 43

// DP Table
// 0 0 0 0 0 0 0 0 0 0 0 
// 0 6 6 6 6 6 6 6 6 6 6 
// 0 6 10 16 16 16 16 16 16 16 16 
// 0 6 10 16 18 22 28 28 28 28 28 
// 0 6 10 16 18 22 28 28 31 31 31 
// 0 6 12 16 22 24 28 34 34 37 37 
// 0 6 12 16 22 24 28 34 34 37 43 