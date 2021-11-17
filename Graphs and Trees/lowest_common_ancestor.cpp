const int maxN = 2e5 + 1;
const int logN = 20;

int p[maxN][logN];
int timer, in[maxN], out[maxN];
vector<int> G[maxN];

void dfs(int u = 1, int par = 1) {
	in[u] = ++timer;
	p[u][0] = par;
	for(int i = 1; i < logN; i++) {
		p[u][i] = p[p[u][i-1]][i - 1];
	}
	for(int v: G[u]) {
		if(v != par) {
			dfs(v, u);
		}
	}
	out[u] = ++timer;
}

bool ancestor(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
	if(ancestor(u, v)) return u;
	if(ancestor(v, u)) return v;

	for(int i = logN - 1; i >= 0; i--) {
		if(!ancestor(p[u][i] , v)) {
			u = p[u][i];
		}
	}
	return p[u][0];
}

void solve()
{
	int N, M, Q, x, y, a, b;
	cin >> N >> M >> Q;
	for(int i = 2; i <= N; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs();

	for(int q = 0; q < Q; q++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < logN; j++) {
			cerr << p[i][j] << " ";
		}
		cerr << "\n";
	}
	cerr << "\n";
	for(int i = 0; i < 25; i++) {
		cerr << in[i] << " ";
	}
	cerr << "\n";

	for(int i = 0; i < 25; i++) {
		cerr << out[i] << " ";
	}
	cerr << "\n";
}

// Input
// 11 10 4
// 1 2
// 2 3
// 3 4
// 3 5
// 4 6
// 4 7
// 5 9
// 2 8
// 8 10
// 8 11
// 11 6
// 7 9
// 4 9
// 6 7

// Output
// 2
// 3
// 3
// 4

// Debugger
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 3 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 5 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 8 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 8 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

// 0 1 2 3 4 10 5 7 15 11 16 18 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 22 21 14 9 13 6 8 20 12 17 19 0 0 0 0 0 0 0 0 0 0 0 0 0 