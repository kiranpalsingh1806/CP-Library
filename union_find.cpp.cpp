struct UnionFind{
    int num;
    vector<int> rs, parent;
    UnionFind(int n): num(n), rs(n, 1), parent(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (rs[x] < rs[y]) swap(x, y);
        rs[x] += rs[y];
        parent[y] = x;
        num--;
    }

    int size(int x) {
        return rs[find(x)];
    }

    int countSets() const {
        return num;
    }
};