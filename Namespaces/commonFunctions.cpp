namespace commonFunctions {
	int gcd(int a, int b) {
		if(b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	int digitNum(int x, int b = 10) {
		int res = 0;
		for(; x; x /= b) {
			res++;
		}
		return res;
	}

	int digitSum(int x, int b = 10) {
		int res = 0;
		for(; x; x /= b) {
			res += x % b;
		}
		return res;
	}
}
using namespace commonFunctions;