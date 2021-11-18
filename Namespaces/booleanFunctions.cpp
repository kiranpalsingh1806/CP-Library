namespace booleanFunctions{
	// returns whether string t subsequence of string s.
	bool isSubsequence(string s, string t) {
	    int match = 0;
	    for (char c: s) {
	        if (c==t[match]) match++;
	        if (match == t.size()) return true;
	    }
	    return false;
	}

	bool isPalindrome(string s){
		if(sz(s) == 0) return true;
		string t = s; reverse(all(t));
		return s == t;
	}

	bool isPowerOfTwo(int n){
	   if(n==0) return false;
	   return (ceil(log2(n)) == floor(log2(n)));
	}

	bool isVowel(char c){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
		return false;
	}

	// returns whether string t is substring of s.
	bool isSubstring(string s, string t){
		if( s.find(t) != string::npos) return true;
		return false;
	}
}
using namespace booleanFunctions;