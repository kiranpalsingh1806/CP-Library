string addStr(const string& a, const string& b) {
	int as = (int)a.size() - 1;
	int bs = (int)b.size() - 1;
	string res;
	int carry = 0;
	for (int i = 0;; ++i) {
		int v = carry;
		carry = 0;
		if (i <= as) v += a[as-i] - '0';
		if (i <= bs) v += b[bs-i] - '0';
		if (v >= 10) {
			v -= 10;
			carry = 1;
		}
		if (i > as && i > bs && v == 0) break;
		res.push_back(v + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}


void solve()
{
	string a, b;
	cin >> a >> b;

	string ans = addStr(a, b);
	cout << ans << "\n";
}

// Input
// 5555
// 4444

// Output
// 9999