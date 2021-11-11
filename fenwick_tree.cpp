
struct FenwickTree {
	vector<int> bit;  // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0ll);
	}

	void add(int idx, int val) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += val;
	}

	int query(int idx) { //
		int ret = 0;
		for (++idx; idx > 0ll; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
	void printBIT() {
		for(int i = 1; i < n; i++) {
			cout << bit[i] << " ";
		}
		cout << "\n";
	}
};

void solve()
{
	int n;
	cin >> n;
	int a[n];

	FenwickTree B1(n);

	for(int i = 0; i < n ; i++) {
		cin >> a[i];
		B1.add(i, a[i]);
	}

	for(int i = 0; i < n; i++) {
		cout << B1.query(i) << "\n";
	}

	B1.printBIT();

	cout << lineSeparator() << "\n";

	// Range update a[1] to a[5]
	for(int i = 0; i <= 4; i++) {
		B1.add(i, 10);
	}

	for(int i = 0; i < n; i++) {
		cout << B1.query(i) << "\n";
	}

	B1.printBIT();
}

// Input 
// 10
// 1 2 3 4 5 6 7 8 9 10

// Output
// 1
// 3
// 6
// 10
// 15
// 21
// 28
// 36
// 45
// 55
// 1 3 3 10 5 11 7 36 9 19 
// ----------------------------------
// 11
// 23
// 36
// 50
// 65
// 71
// 78
// 86
// 95
// 105
// 11 23 13 50 15 21 7 86 9 19 
