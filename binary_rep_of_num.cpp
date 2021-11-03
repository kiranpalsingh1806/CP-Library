int val = 31;
	for (int i = 31; i >= 0; i--) {
	if (val&(1<<i)) cout << "1";
	else cout << "0";
	}