struct city {
	string name;
	int score, index;
};

int n;

bool comp(const city a, const city b) {
	if(a.name != b.name) {
		return a.name < b.name;
	}
	return a.score > b.score;
}

void solve() {
	cin >> n;
	vector<city> cities(n);
	for(int i = 0; i < n; i++) {
		cin >> cities[i].name >> cities[i].score;
		cities[i].index = i + 1;
	}	

	sort(cities.begin(), cities.end(), comp);

	for(int i = 0; i < n; i++) {
		cout << cities[i].index << "\n";
	}
}

// Problems
// https://atcoder.jp/contests/abc128/tasks/abc128_b

// Input
// 6
// khabarovsk 20
// moscow 10
// kazan 50
// kazan 35
// moscow 60
// khabarovsk 40

// Output
// 3
// 4
// 6
// 1
// 5
// 2

