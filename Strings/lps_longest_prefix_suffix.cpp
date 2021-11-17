 
// Longest prefix which is also suffix
// The prefix and suffix should not overlap
vector<int> computeLPS(string t) {
	int m = t.length();
    vector<int> lps(m);
 
    int i = 1, len = 0;
    lps[0] = 0;
 
    while (i < m) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve()
{
	string a, b;
    cin >> a >> b;  

    auto A = computeLPS(a);
    auto B = computeLPS(b);

    for(auto &a: A) {
        cout << a << " ";
    }
    cout << "\n";

    for(auto &b: B) {
        cout << b << " ";
    }
    cout << "\n";
}

// Input
// abcdabcdabcd
// abcdefabcdefabcdef
// Output
// 0 0 0 0 1 2 3 4 5 6 7 8 
// 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 
