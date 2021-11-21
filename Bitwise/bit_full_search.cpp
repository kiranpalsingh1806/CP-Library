int n = 8;

for (int bit = 0; bit < (1<<n); ++bit)
{
    vector<int> S;
    for (int i = 0; i < n; ++i) {
        if (bit & (1<<i)) { 
            S.push_back(i);
        }
        debug(1<< i);
    }

    cout << bit << ": {";
    for (int i = 0; i < (int)S.size(); ++i) {
        cout << S[i] << " ";
    }
    cout << "}" << endl;
}

// Problems
// https://atcoder.jp/contests/abc197/tasks/abc197_c