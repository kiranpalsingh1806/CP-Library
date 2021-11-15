
// Minimum heap and Maximum heap
void solve()
{
	priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int, vector<int> > maxHeap;

	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		minHeap.push(x);
		maxHeap.push(x);
	}

	auto a = minHeap;
	while(!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
	cout << "\n";

	auto b = maxHeap;
	while(!b.empty()) {
		cout << b.top() << " ";
		b.pop();
	}
	cout << "\n";
}

// Input
// 8
// 1 5 2 19 23 9 7 33
// Output
// 1 2 5 7 9 19 23 33 
// 33 23 19 9 7 5 2 1 
