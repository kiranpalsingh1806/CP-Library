#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_SIDE = 1000;
int prefixSum2D[MAX_SIDE + 1][MAX_SIDE + 1];
int array2D[MAX_SIDE + 1][MAX_SIDE + 1];

void solve()
{
	int N;
	int Q;
	cin >> N >> Q;
	// read in the initial trees
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> array2D[i][j];
		}
	}

	// build the prefix sum array
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefixSum2D[i][j] = array2D[i][j]
						+ prefixSum2D[i - 1][j]
						+ prefixSum2D[i][j - 1]
						- prefixSum2D[i - 1][j - 1];
		}
	}

	for (int q = 0; q < Q; q++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << prefixSum2D[x2][y2]
				- prefixSum2D[x1-1][y2]
				- prefixSum2D[x2][y1-1]
				+ prefixSum2D[x1-1][y1-1] << '\n';
	}

}

int main(void) {
	solve();
}