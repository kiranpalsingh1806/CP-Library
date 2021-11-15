#include<bits/stdc++.h>
using namespace std;

// Convert To Decimal From Base K
int convertToDecimal(string s, int k) {
  int ans = 0;
  for(char x: s) {
    ans *= k;
    ans += x - '0';
  } return ans;
}

int main(){
    int k;
    string a,b;
    cin >> k >> a >> b;
    int A = convertToDecimal(a, k);
    int B = convertToDecimal(b, k);
    cout << A*B << endl;
    return 0;
}