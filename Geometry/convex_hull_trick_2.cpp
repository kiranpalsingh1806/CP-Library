#include<bits/stdc++.h>
using namespace std;

template <class T>
class ConvexHullTrick {
    struct Line {
        T a, b;
        Line(const T& a, const T& b) : a(a), b(b){};
        T operator()(const T& x) const { return a * x + b; }
    };
 
public:
    std::vector<Line> lines;
    bool isMonotonicX;
 
    explicit ConvexHullTrick(bool xflag = false) : isMonotonicX(xflag){};
 
    // l2が必要か否か
    bool isneeded(Line l1, Line l2, Line l3) const {
        if (l1.a < l3.a) std::swap(l1, l3);
        return (l3.b - l2.b) * (l2.a - l1.a) < (l3.a - l2.a) * (l2.b - l1.b);
    }
 
    // 直線y = ax + bを追加  aは単調であることを要求
    void add(const T& a, const T& b) {
        Line line(a, b);
        while (lines.size() >= 2 &&
               !isneeded(*(lines.end() - 2), lines.back(), line)) lines.pop_back();
        lines.push_back(line);
    }
 
    // xにおける最小値を返す
    T operator()(const T& x) const {
        if (isMonotonicX) {
            static int itr = 0;
            while (itr + 1 < (int)lines.size() && lines[itr](x) > lines[itr + 1](x)) ++itr;
            return lines[itr](x);
        } else {
            // l[ok - 1](x) > l[ok](x)
            int ok = 0, ng = lines.size();
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (lines[mid - 1](x) > lines[mid](x)) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            return lines[ok](x);
        }
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ConvexHullTrick<T>& cht) {
    os << "{";
    for (const auto& l : cht.lines) os << "(" << l.a << "," << l.b << "),";
    return os << "}";
}
 
using namespace std;
using lint = long long;
constexpr lint INF = 1LL << 60;