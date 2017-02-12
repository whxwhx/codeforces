#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 3010;
typedef long long LL;
int a[N], b[N], l = 0;
LL f[N][N];
LL ab(int x) { return x < 0 ? -x : x; }
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]), a[i] -= i, b[i] = a[i];
	sort(b + 1, b + n + 1); l = unique(b + 1, b + n + 1) - b - 1;
	rep(j,1,l) f[1][j] = ab(a[1] - b[j]);
	rep(i,1,n) {
		rep(j,1,l) {
			f[i][j] = f[i - 1][j] + ab(a[i] - b[j]);
			if (j - 1) f[i][j] = min(f[i][j], f[i][j - 1]);
		}
	}
	LL ans = 1LL << 62;
	rep(j,1,l) if (f[n][j] < ans) ans = f[n][j];
	cout <<ans<<endl;
	return 0;
}