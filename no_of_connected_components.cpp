vector<int> G[100];

vector<bool> seen;
void dfs(int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v); 
    }
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

    int count = 0;
    seen.assign(100, false);
    for (int v = 1; v <=N; ++v) {
        if (seen[v]) continue; // Through if v has been searched
        dfs(v); // If v is unsearched, perform DFS starting from v
        ++count;
    }
    cout << count << endl;
}