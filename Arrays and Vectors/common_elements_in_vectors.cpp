

void solve()
{
	int n, m, countCommon = 0;

	cin >> n;
	vector<int> vec1(n);
	for(int i = 0; i < n; i++) {
		cin >> vec1[i];
	}

	cin >> m;
	vector<int> vec2(m);
	for(int i = 0; i < m; i++) {
		cin >> vec2[i];
	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	vector<int> v(vec1.size() + vec2.size());
	debug(v);

	auto it = set_intersection(vec1.begin(), vec1.end(),vec2.begin(), vec2.end(),v.begin());

	debug(v);
	cout << "Common Elements : " << it - v.begin() << "\n";
	cout << "The elements are : ";

	for ( auto st = v.begin(); st != it; ++st) {
		cout << *(st) << " ";
	}
}

// Input
// 6
// 1 3 5 7 8 9
// 7
// 1 2 3 7 9 4 8
// Output
// Common Elements : 5
// The elements are : 1 3 7 8 9 