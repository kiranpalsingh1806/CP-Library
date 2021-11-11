// Counting pairs in array

// Count pairs in array such that i < j and a[i] * a[j] = i + j
int countPairs1(int a[], int n) {
	int count = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = a[i] - i; j <= n; j += a[i]) {
			if(j > i) {
				if(i + j == a[i] * a[j]) {
					count++;
				}
			}
		}
	}
	return count;
}


void solve()
{
	int n;
	cin >> n;
	int a[n+1];

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans = countPairs1(a, n);
	cout << ans << "\n";
}


// For countPairs1
// Input
// 5
// 3 1 5 9 2
// Output
// 3
// (1,2), (1,5) and (2,3)