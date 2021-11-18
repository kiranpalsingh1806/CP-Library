
int maxPathSumInTwoArrays(int arr1[], int arr2[], int m, int n) {
	int i = 0, j = 0;
	int result = 0, sum1 = 0, sum2 = 0;

	while(i < m && j < n) {
		if(arr1[i] < arr2[j]) {
			sum1 += arr1[i++];
		} else if(arr1[i] > arr2[j]) {
			sum2 += arr2[j++];
		} else {
			result += max(sum1, sum2) + arr1[i];

			sum1 = 0;
			sum2 = 0;

			i++;
			j++;
		}
	}

	while(i < m) {
		sum1 += arr1[i++];
	}
	while(j < n) {
		sum2 += arr2[j++];
	}

	result += max(sum1, sum2);
	return result;
}

int arr1[100005];
int arr2[100005];
int m, n;

void solve()
{
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> arr1[i];
	}

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	
    cout << "Maximum sum path is " << maxPathSumInTwoArrays(arr1, arr2, m, n);
}


// Input
// 8
// 2 3 7 10 12 15 30 34
// 8
// 1 5 7 8 10 15 16 19
// Output
// Maximum sum path is 122