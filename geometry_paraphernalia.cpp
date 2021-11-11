
namespace GeometryParaphernalia{
	struct coordinate {
	    int x, y;
	};

	int ManhattanDistance(const coordinate &a, const coordinate &b) {
	    return abs(a.x - b.x) + abs(a.y - b.y);
	}

	double EuclideanDistance(const coordinate &a, const coordinate &b){
		return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y,2) * 1.0);
	}

	struct coordinate3D{
		int x, y, z;
	};

	double Euclidean3D_Distance(const coordinate3D &a, const coordinate3D &b){
		return sqrt( pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2) * 1.0);
	}

	// Usage for finding 3D Euclidean Distance:
	// vector<coordinate3D> points3D(N);
	// for(auto &point : points3D) cin >> point.x >> point.y >> point.z;
}
using namespace GeometryParaphernalia;

void solve()
{
	int a, b, n, q;
	cin >> n >> q;
    vector<coordinate> points(n);
    for(auto &point: points) {
    	cin >> point.x >> point.y;
    }

    for(int i = 0; i < q; i++) {
    	cin >> a >> b;
    	double manhattan = ManhattanDistance(points[a], points[b]);
    	double euclid = EuclideanDistance(points[a], points[b]);
    	cout << manhattan << " " << euclid << "\n";
    }

}

// Input
// 4 3
// 1 1
// 1 4
// 4 1
// 4 4
// 0 3
// 0 1
// 1 3

// Output
// 6 4.24264
// 3 3
// 3 3
