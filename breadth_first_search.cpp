    
void solve()
{
    int n, m;
    cin>> n >> m;
    vector<int> adj[n+1];
    memset(adj, 0, sizeof adj);

    rep(i,1,m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // Source Vertex
    int s = 1;
    
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> d(n+1), p(n+1);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    // Check if there is any path between source vertex and vertex u.
    int u = 4;

    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}

// Input
// 5 5
// 1 2
// 2 3
// 3 4
// 4 1
// 2 4

// Output
// Path: 1 4 
