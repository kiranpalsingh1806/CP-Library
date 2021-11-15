const ll MAXN = 1e7;
bool comp[MAXN + 10];
vector<ll> primeVec;

void sieveOfEratosthenes()
{
   for(int i = 2; i <= MAXN; i++){
        if(comp[i]) continue;
        primeVec.pb(i);        
        for(int j = 2 * i; j <= MAXN; j += i){
            comp[j] = true;
        }
    }
}

int L,R;

void solve()
{
    // Implementation
    sieveOfEratosthenes();
    cin >> L >> R;
    // For finding prime numbers in range L,R
    ll rangeAns = (upper_bound(primeVec.begin(), primeVec.end(), R)
                 - upper_bound(primeVec.begin(), primeVec.end(), L));

    cout << rangeAns;
}

// Input - > 1 100
// Output -> 25 (25 Prime numbers between 2 and 100 inclusive)