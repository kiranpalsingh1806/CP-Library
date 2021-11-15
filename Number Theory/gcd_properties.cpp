// Basic GCD
int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// Finding maximum gcd of two numbers a and b in range [L, R]
// in O(n) time instead of O(n ^ 2) time.
	cin >> L >> R;
	int maxGCD = -1e9;
	int operations = 0;

	for(int i = L; i <= R; i++) {
		for(int j = i + 1; j <= R; j++) {
			maxGCD = max(maxGCD, int(gcd(i, j)));
			operations++;
		}
	}

	cout << maxGCD << "\n";
	int modifiedOperations = 0;

	for(int c = R; c > 0; c--) {
		modifiedOperations++;
		if((L + c - 1) / c < R / c) {
			cout << c << "\n";
			goto end;
		}
	}
	end:;

	cout << operations << "\n";
	cout << modifiedOperations << "\n";

	// Input
	// 100 279
	// Output
	// 139
	// 139
	// 16110
	// 141


