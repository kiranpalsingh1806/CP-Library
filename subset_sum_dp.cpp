vector< vector<int>> tab(2000, vector<int>(2000, -1));

int subsetSum(vector<int> &a, int n, int sum) {
    if (sum == 0) {
    	return 1; 
    } 
    if (n <= 0) {
    	return 0;
    } 

    if (tab[n - 1][sum] != -1) {
        return tab[n - 1][sum];
    }

    if (a[n - 1] > sum) {
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    }
    else{
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
        						 subsetSum(a, n - 1, sum - a[n - 1]);
 	}
}

void solve()
{
    int n = 5;
    vector<int> a = {13, 1, 5, 2, 22, 17};
    int sum = 21;
 
    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}