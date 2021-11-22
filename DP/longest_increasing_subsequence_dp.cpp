#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf 1e18

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

int main() {
    solve();
}

// Input
// 15
// 1 3 5 7 2 4 6 8 9 10 2 3 17 11 12 
// Output
// 9

// DP Array
// for(int i = 0; i < n; i++) {
//         cout << dp[i] << " ";
//     }
//     cout << "\n";
// 1 2 3 6 8 9 10 11 12 100000 100000 100000 100000 100000 100000 