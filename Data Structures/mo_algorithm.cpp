const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;
 
struct data
{
	int l, r, idx;
} qr[Q];
 
int n, q, a[N];
int freq[M];
long long ans[Q];
long long cur = 0;
 
bool comp(struct data &d1, struct data &d2) {
	int b1 = d1.l / SZ;
	int b2 = d2.l / SZ;
	if(b1 != b2) {
		return b1 < b2;
	}
	else {
		return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
	}
}
 
inline void add(int x) {	
	cur -= 1LL * freq[x] * freq[x] * x;
	freq[x]++;
	cur += 1LL * freq[x] * freq[x] * x;
}
 
inline void remove(int x) {
	cur -= 1LL * freq[x] * freq[x] * x;
	freq[x]--;
	cur += 1LL * freq[x] * freq[x] * x;
}
 
void mo() {
	for(int i = 1; i <= q; i++) {
		cerr <<"Query " << i << " : " << qr[i].l << " " << qr[i].r << " " << qr[i].idx << "\n";
	}
	cerr << lineSeparator() << "\n";

	cerr << "After sorting queries" << "\n";
	sort(qr + 1, qr + q + 1, comp);
	for(int i = 1; i <= q; i++) {
		cerr <<"Query " << i << " : " << qr[i].l << " " << qr[i].r << " " << qr[i].idx << "\n";
	}
	cerr << lineSeparator() << "\n";
	int l = 1, r = 0;
	cur = 0;
	for(int i=1; i<=q; i++) {
		while(l < qr[i].l) remove(a[l++]);
		cerr << "The val of cur in 1st while in Query " << i << " : " << cur << "\n";
		while(l > qr[i].l) add(a[--l]);
		cerr << "The val of cur in 2nd while in Query " << i << " : " << cur << "\n";
		while(r < qr[i].r) add(a[++r]);
		cerr << "The val of cur in 3rd while in Query " << i << " : " << cur << "\n";
		while(r > qr[i].r) remove(a[r--]);
		cerr << "The val of cur in 4th while in Query " << i << " : " << cur << "\n";
		ans[qr[i].idx] = cur;
		cerr << lineSeparator() << "\n";
	}

	cerr << "Answer Array" << "\n";
	for(int i = 1; i <= q; i++) {
		cerr << ans[i] << "\n";
	}
	cerr << lineSeparator() << "\n";
}

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= q; i++) {
		cin >> qr[i].l >> qr[i].r;
		qr[i].idx = i;
	}
	mo();
	for(int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
}

// Problem
// https://codeforces.com/contest/86/problem/D

// Input
// 20 5
// 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2
// 4 15
// 1 2
// 2 20
// 7 7
// 13 18

// Output
// 108
// 3
// 281
// 1
// 27

// Debugger
// Query 1 : 4 15 1
// Query 2 : 1 2 2
// Query 3 : 2 20 3
// Query 4 : 7 7 4
// Query 5 : 13 18 5
// ----------------------------------
// After sorting queries
// Query 1 : 2 20 3
// Query 2 : 13 18 5
// Query 3 : 4 15 1
// Query 4 : 7 7 4
// Query 5 : 1 2 2
// ----------------------------------
// The val of cur in 1st while in Query 1 : 1
// The val of cur in 2nd while in Query 1 : 1
// The val of cur in 3rd while in Query 1 : 281
// The val of cur in 4th while in Query 1 : 281
// ----------------------------------
// The val of cur in 1st while in Query 2 : 48
// The val of cur in 2nd while in Query 2 : 48
// The val of cur in 3rd while in Query 2 : 48
// The val of cur in 4th while in Query 2 : 27
// ----------------------------------
// The val of cur in 1st while in Query 3 : 27
// The val of cur in 2nd while in Query 3 : 177
// The val of cur in 3rd while in Query 3 : 177
// The val of cur in 4th while in Query 3 : 108
// ----------------------------------
// The val of cur in 1st while in Query 4 : 57
// The val of cur in 2nd while in Query 4 : 57
// The val of cur in 3rd while in Query 4 : 57
// The val of cur in 4th while in Query 4 : 1
// ----------------------------------
// The val of cur in 1st while in Query 5 : 1
// The val of cur in 2nd while in Query 5 : 34
// The val of cur in 3rd while in Query 5 : 34
// The val of cur in 4th while in Query 5 : 3
// ----------------------------------
// Answer Array
// 108
// 3
// 281
// 1
// 27
// ----------------------------------
