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

// Count pairs such that i < j and a[i] != a[j]
int countPairs2(int a[], int n) {
	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		mp[a[i]]++;
	}
	int count = n * (n - 1) / 2;
	for(auto a: mp) {
		count -= (a.second * a.second - 1) / 2;
	}
	return count;
}

// Count pairs such that i < j and a[i] - a[j] is a multiple of 200.
int countPairs3(int a[], int n) {
	map<int, int> mp;
	for(int i = 0; i <= n; i++) {
		a[i] %= 200;
		mp[a[i]]++;
	}
	int count = 0;
	for(auto a: mp) {
		count += a.second * (a.second - 1) / 2;
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

// For countPairs2
// Input
// 10
// 1 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
// Output
// 45

// For countPairs3
// Input
// 8
// 199 100 200 400 300 500 600 200
// Output
// 9

