void solve()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	do {
		cout << s << "\n";
	} while(next_permutation(s.begin(), s.end()));
}

// Input
// abcd

// Ouput
// abcd
// abdc
// acbd
// acdb
// adbc
// adcb
// bacd
// badc
// bcad
// bcda
// bdac
// bdca
// cabd
// cadb
// cbad
// cbda
// cdab
// cdba
// dabc
// dacb
// dbac
// dbca
// dcab
// dcba
