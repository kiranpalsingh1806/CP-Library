// Returns sum of two numbers a and b with given base 
int sumWithBase(string a, string b, int base)
{
    int len_a, len_b;
 
    len_a = a.size(); len_b = b.size();
 
    string sum, s;
    s = "";
    sum = "";
 
    int diff;
    diff = abs(len_a - len_b);
 
    for (int i = 1; i <= diff; i++) s += "0";
 
    if (len_a < len_b) a = s + a;
    else b = s + b;
 
    int curr, carry = 0;
 
    for (int i = max(len_a, len_b) - 1; i > -1; i--) 
    {
        curr = carry + (a[i] - '0') + (b[i] - '0');
        carry = curr / base;
        curr = curr % base;
        sum = (char)(curr + '0') + sum;
    }

    if (carry > 0) sum = (char)(carry + '0') + sum;
    
    int ans = stoi(sum);
    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << sumABwithBase(a, b, 10);
}

// Input
// 11 12
// Output
// 23