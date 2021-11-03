
int LIS(vector<ll> &a) {
    int n = a.size();
    vector<ll> dp(n, inf);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

void solve()
{
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << LIS(a) << endl;
}

// Input
// 1 2 3 4 5 6
// Output
// 6