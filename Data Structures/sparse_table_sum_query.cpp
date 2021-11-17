

const ll MAXN = 100005; // MAXN is biggest possible array length
const ll K = 25;
ll st[MAXN][K + 1];
ll n,q;
ll arr[10];

//Taking array of n elements as input
cin>>n>>q;
rep(i,0,n-1) cin>>arr[i];

//Precomputation
for (ll i = 0; i <n; i++)
    st[i][0] = arr[i];

for (ll j = 1; j <= K; j++)
    for (ll i = 0; i + (1 << j) <= n; i++)
        st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];

//Answering the queries
rep(i,1,q)
	{
		ll L,R;
		ll sum = 0;
		cin>>L>>R;
		L--; R--; // Array is 0-indexed

		for (ll j = K; j >= 0; j--) 
		{
		    if ((1 << j) <= R - L + 1) 
		    {
		        sum += st[L][j];
		        L += 1 << j;
		    }
		}
		cout<<sum<<nline;
	}

