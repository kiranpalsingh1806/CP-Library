/* The Chicken McNugget Theorem states that for any two relatively prime positive
integers m and n, the greatest integer that cannot that cannot be written
in the form a*m + b *n for non-negative integers a, b is mn - m - n.  */

bool chickenMcNuggetTheorem(int m, int n, int number) {
	for(int i = 0; i <= 10; i++) {
		int y = number - i * n;
		if(y >= 0 && y % m == 0) {
			return true;
		}	
	}
	return false;
}

bool chickenMcNuggetTheoremModified(int m, int n, int number) {
	if(number >= n * (number % m)) {
		return true;
	} else {
		return false;
	}
}

void solve()
{
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(chickenMcNuggetTheoremModified(11, 111, n)) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}
}

// Input
// 3
// 33
// 144
// 69

// Output
// YES
// YES
// NO
