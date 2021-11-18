namespace sieve {
	const ll MAXN = 1e7;
	bool comp[MAXN + 10];
	vector<ll> primeVec;

	void sieveOfEratosthenes() {
	   for(int i = 2; i <= MAXN; i++){
	        if(comp[i]) continue;
	        primeVec.pb(i);        
	        for(int j = 2 * i; j <= MAXN; j += i){
	            comp[j] = true;
	        }
	    }
	};

	ll getPrimeExponents(ll x) {
	    ll ret = 0;
	    for(auto i : primeVec) {
	        while(x % i == 0) {
	            ret++;
	            x /= i;
	        }
	    }
	    if(x > 1) ret++;
	    return ret;
	}
}
using namespace sieve;