typedef double T;
struct pt {
	T x, y;
	pt operator+ (pt p) {
		return {x + p.x, y + p.y};
	}

	pt operator- (pt p) {
		return {x - p.x, y - p.y};
	}

	pt operator* (T d) {
		return { x * d, y * d};
	}

	pt operator/ (T d) {
		return {x/d, y/d};
	}
};

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

bool operator!= (pt a, pt b) {
	return !(a == b);
}

T sq(pt p) {
	return p.x * p.x + p.y * p.y;
}

double abs(pt p) {
	return sqrt(sq(p));
}

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << "," << p.y << ")";
}

void solve()
{
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << a+b << " " << a-b << "\n"; 
    cout << a*-1 << " " << b/2 << "\n"; 

    pt c;
    cin >> c.x >> c.y;
    cout << abs(c) << "\n";
}

// Input
// 3 4
// 2 -1
// -5 -10

// Output
// (5,3) (1,5)
// (-3,-4) (1,-0.5)
// 11.1803
