
const int N = 3e5 + 9;
int n, m;
vector<pair<int, int>> g[N];


// First parameter is source vertex and second is adjacency list
vector<long long> dijkstra(int s, vector<pair<int, int>> g[])
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> d(n + 1, 1e18); vector<bool> vis(n + 1, 0);
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()){
        auto x = q.top(); q.pop();
        int u = x.second;
        if(vis[u]) continue; vis[u] = 1;
        for(auto y: g[u]){
            int v = y.first; long long w = y.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w; q.push({d[v], v});
            }
        }
    }
    return d;
}

 
int u[N], v[N], w[N];
void solve()
{
	cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
    }

    auto d1 = dijkstra(1, g);
    auto d2 = dijkstra(5, g);
    auto d3 = dijkstra(8, g);

    for(int i = 1; i <= n; i++) {
    	cout << d1[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
    	cout << d2[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
    	cout << d3[i] << " ";
    }
    cout << "\n";
}

// Input
// 8 13
// 1 2 2
// 1 3 9
// 2 3 7
// 2 4 8
// 3 5 3
// 4 5 2
// 5 6 1
// 1 7 3
// 7 8 2
// 8 5 3
// 7 6 6
// 8 3 2
// 1 8 8

// Output
// 0 2 7 10 8 9 3 5 
// 8 10 3 2 0 1 5 3 
// 5 7 2 5 3 4 2 0 
