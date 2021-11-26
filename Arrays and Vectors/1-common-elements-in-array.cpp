#include<bits/stdc++.h>
using namespace std;

int main() {
	int countCommon = 0;
	int n = 6;
	vector<int> vec1 = {1, 3, 5, 7, 8, 9};
	int m = 7;
	vector<int> vec2 = {1, 2, 3, 7, 9, 4, 8};

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	vector<int> v(vec1.size() + vec2.size());

	auto it = set_intersection(vec1.begin(), vec1.end(),vec2.begin(), vec2.end(),v.begin());

	cout << "Common Elements : " << it - v.begin() << "\n";
	cout << "The elements are : ";

	for ( auto st = v.begin(); st != it; ++st) {
		cout << *(st) << " ";
	}
}