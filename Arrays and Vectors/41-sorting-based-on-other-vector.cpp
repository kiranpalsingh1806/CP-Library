#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 7;
    vector<int> a = {4, 8, 1, 3, 2, 9, 11};
    
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    for(auto a: ind) {
        cout << a << " ";
    }
    cout << "\n";
    
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    for(auto a: ind) {
        cout << a << " ";
    }
    cout << "\n";
}