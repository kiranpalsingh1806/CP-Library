void solve()
{
	int n;
	cin >> n;
	vector<string> s(n);

	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end(), [&](string x, string y) {
        return count(x.begin(), x.end(), '1') < count(y.begin(), y.end(), '1');
    });

    for(int i = 0; i < n; i++) {
    	cout << s[i] << "\n";
    }
}

// Input
// 5
// 10101
// 10000000
// 010101
// 00111111
// 11000000000

// Output
// 10000000
// 11000000000
// 10101
// 010101
// 00111111
