namespace bitwiseContrivance{
	int getFirstSetBitPos(int n){
	    return log2(n & -n) + 1;
	}

	int findXOR(int n){
	    int mod = n % 4; if (mod == 0) return n;
	    else if (mod == 1) return 1;
	    else if (mod == 2) return n + 1;
	    else if (mod == 3) return 0;
	}

	int XorInRange(int l, int r){
	    return (findXOR(l - 1) ^ findXOR(r));
	}

	int AndInRange(int x, int y){
	    for(int i = 0; i < (int)log2( y ) + 1; i++){
	        if (y <= x) return y;
	        if (y & (1 << i)) y &= ~(1UL << i);
	    }
	    return y;
	}

	int turnOffKthBit(int n, int k){
		if (k <= 0) return n;
		return (n & ~(1 << (k - 1)));
	}

	int turnOnKthBit(int n, int k){
		if (k <= 0) return n;
	    return (n | (1 << (k - 1)));
	}

	int toggleKthBit(int n, int k){
		return (n ^ (1 << (k - 1)));
	}

	void GreyCode(int n){
	    for (int i = 0; i < (1 << n); i++){
	    	int val = (i ^ (i >> 1));
	        bitset<32> r(val);
	        string s = r.to_string();
	        cout << s.substr(32 - n) << " ";
	    }
	}

	int unsetRightMostBit(int n){
		return n & (n -1);
	}

	int parityOfNumber(int n){
		// Returns 1 if odd parity -> odd number of ones.
		int ans = __builtin_parity(n);
		return ans;
	}

	int countLeadingZeroes(int n){
		int ans = __builtin_clz(n);
		return ans;
	}

	int countTrailingZeroes(int n){
		int ans = __builtin_ctz(n);
		return ans;
	}

	int countSetBits(int n){
		int ans = __builtin_popcount(n);
		return ans;
	}

	string binaryRepresentation(int n){
		bitset<8> b(n);
		string ans = b.to_string();
		return ans;
	}
}
using namespace bitwiseContrivance;