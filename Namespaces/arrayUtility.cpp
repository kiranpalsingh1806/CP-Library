namespace arrayUtility{
    template<typename T>
    void printArray(T a[], ll s, ll t)
    {
        for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}
        cout << endl;
    }

    template<typename T>
    void debugArray(T a[], ll s, ll t)
    {
        cerr<<"[Array] = [";
        for(ll i = s; i <= t; i++){ cerr << a[i]; if(i<t) cerr<<","; if(i < t) cerr << "";}
        cerr<<"]";
        cerr << endl;
    }
}
using namespace arrayUtility;