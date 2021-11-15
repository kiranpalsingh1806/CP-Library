
ll maxSumSubarray (vector<ll> A) {
	ll n = A.size();
	ll local_max = 0;
	ll global_max = -inf;
	for (ll i=0; i<n; i++) {
			local_max = max(A[i], A[i] + local_max);

			if (local_max > global_max){
				global_max = local_max;
			}	
	}
	return global_max;
}


void solve()
{ 
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll mx = maxSumSubArray(a);
	cout<<mx<<nline;
}