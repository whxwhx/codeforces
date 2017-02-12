#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const double eps = 1e-12;
int n, L, v1, v2, k; 
bool check(double d) {
	int rest = n; double rest_dis = L;
	for(;rest > 0 && rest_dis > 0;) {
		if (rest_dis < d) return false;
		rest -= k; double delta = d / v2 * v1;
		rest_dis -= delta + (d - delta) / (v2 + v1) * v1;
	}
	return true;
}
int main() {
	cin >>n>>L>>v1>>v2>>k;
	double l = 0, r = L; int t = 0;
	while (l + eps < r) {
		double mid = (l + r) / 2; t++; if (t > 5000) break;
		if (check(mid)) l = mid; else r = mid;
	}
	double x = (l + r) / 2;
	printf("%.10lf\n", (L - x) / v1 + x / v2);
	return 0;
}