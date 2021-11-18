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
	// Usage for finding Euclidean Distance :
	// vector<coordinate> towers(N);
	// for (auto &tower : towers) cin >> tower.x >> tower.y;

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