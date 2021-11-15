
vector< int > euler_phi_table(int n) {
  vector< int > euler(n + 1);
  for(int i = 0; i <= n; i++) {
    euler[i] = i;
  }
  for(int i = 2; i <= n; i++) {
    if(euler[i] == i) {
      for(int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}

template< typename T >
T euler_phi(T n) {
  T ret = n;
  for(T i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ret -= ret / n;
  return ret;
}

void EulerPhiDemo(int n) {
  int countPhi = 0;
  vector<int> whichNum;
  for(int i = 0; i <= n; i++) {
    if(gcd(i, n) == 1) {
      whichNum.push_back(i);
      countPhi++;
    }
  }
  cout << "Euler Phi of " << n << " : " << countPhi << "\n";
  cout << "The numbers are : ";
  for(auto &a: whichNum){
    cout << a << " ";
  }
  cout << "\n";
}

void solve()
{
	auto eulerTable = euler_phi_table(100);
	for(auto &a: eulerTable) {
		cout << a << " ";
	}
	cout << "\n";

	auto eulerNumber = euler_phi(20);
	cout << eulerNumber << "\n";

  EulerPhiDemo(5);
  EulerPhiDemo(11);
  EulerPhiDemo(20);
}

// Output
// Euler Phi Table
// 0 1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8
// 16 6 18 8 12 10 22 8 20 12 18 12 28
// 8 30 16 20 16 24 12 36 18 24 16 40
// 12 42 20 24 22 46 16 42 20 32 24 
// 52 18 40 24 36 28 58 16 60 30 36
// 32 48 20 66 32 44 24 70 24 72 36
// 40 36 60 24 78 32 54 40 82 24 64
// 42 56 40 88 24 72 44 60 46 72 32
// 96 42 60 40 

// Euler Phi Number
// 8

// Euler Phi Demo
// Euler Phi of 5 : 4
// The numbers are : 1 2 3 4 
// Euler Phi of 11 : 10
// The numbers are : 1 2 3 4 5 6 7 8 9 10 
// Euler Phi of 20 : 8
// The numbers are : 1 3 7 9 11 13 17 19 

