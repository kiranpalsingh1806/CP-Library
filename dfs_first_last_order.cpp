vector<int> G[100];
vector<int> first_order;
vector<int> last_order;
vector<bool>seen;

void dfs(int v, int& first_ptr, int& last_ptr) {
    first_order[v] = first_ptr++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v, first_ptr, last_ptr);
    }
    last_order[v] = last_ptr++;
}

void solve()
{ 
	int N, M; cin >> N >> M;

	for (int i = 1; i <=M; ++i) {
	    int a, b;
	    cin >> a >> b;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}

	seen.assign(100, false);
	first_order.resize(100);
    last_order.resize(100);
	int first_ptr = 0, last_ptr = 0;
	dfs(0, first_ptr, last_ptr);

	for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}