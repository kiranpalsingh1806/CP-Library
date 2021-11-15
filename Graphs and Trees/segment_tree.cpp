
int n; // Size of array
int a[100005];
int t[100005*4];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve()
{
        // Implementation
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    //Building segment tree
    build(a, 1, 0, n-1);
    cout << sum(1, 0, n-1, 0, 0) << nline;
    cout << sum(1, 0, n-1, 0, 1) << nline;
    cout << sum(1, 0, n-1, 0, 2) << nline;
    cout << sum(1, 0, n-1, 0, 3) << nline;
    cout << sum(1, 0, n-1, 0, 4) << nline;
    cout << sum(1, 0, n-1, 0, 7) << nline;
    cout << lineSeparator() << nline;

    for(int i = 0; i<=2*n; i++) {
        cout << t[i] << " ";
    }
    cout << lineSeparator() << "\n";

    //Updating segment tree
    update(1, 0, n-1, 2, 10);
    outl("Updated 3rd position with 10");
    cout << lineSeparator() << "\n";

    for(int i = 0; i<=2*n; i++) {
        cout << t[i] << " ";
    }
    cout << lineSeparator() << "\n";

    cout << sum(1, 0, n-1, 0, 0) << nline;
    cout << sum(1, 0, n-1, 0, 1) << nline;
    cout << sum(1, 0, n-1, 0, 2) << nline;
    cout << sum(1, 0, n-1, 0, 3) << nline;
    cout << sum(1, 0, n-1, 0, 4) << nline;
    cout << sum(1, 0, n-1, 0, 7) << nline;

    cout << lineSeparator() << "\n";
    for(int i = 0; i<=2*n; i++) {
        cout << t[i] << " ";
    }
    cout << lineSeparator() << "\n";

    update(1, 0, n-1, 4, 20);
    outl("Updated 5th position with 20");
    cout << lineSeparator() << "\n";

    for(int i = 0; i<=2*n; i++) {
        cout << t[i] << " ";
    }
    cout << lineSeparator() << "\n";

    cout << sum(1, 0, n-1, 0, 0) << nline;
    cout << sum(1, 0, n-1, 0, 1) << nline;
    cout << sum(1, 0, n-1, 0, 2) << nline;
    cout << sum(1, 0, n-1, 0, 3) << nline;
    cout << sum(1, 0, n-1, 0, 4) << nline;
    cout << sum(1, 0, n-1, 0, 7) << nline;
}