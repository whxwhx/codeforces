#include <iostream>
#include <cstdio>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i <= (b); i++)
typedef long long LL;
using namespace std;
LL calc(int a, int i, int *b) {
	LL ans = 0;
	if (a < 0) return 0; else a += 2; int c[4] = {1, -1, -1, 1};
	rep(s,0,3) {
		int t = a, cnt = 0;
		rep(k,0,2) if (k != i) t -= (s >> cnt & 1) ? b[k] : 0, cnt++;
		if (t >= 0) ans += 1LL * t * (t - 1) / 2 * c[s];
	}
	return ans;
}

int main() {
	int a[3], l; cin >>a[0]>>a[1]>>a[2]>>l; long long ans = 0;
	rep(i,0,2) {
		rep(j,0,l) {
			bool f = true;
			rep(k,0,2) if (mp(a[k], k) > mp(a[i] + j, i)) { f = false; break; }
			if (!f) continue;
			int b[3]; 
			rep(k,0,i - 1) b[k] = a[i] + j - a[k] + 1;
			rep(k,i + 1,2) b[k] = a[i] + j - 1 - a[k] + 1;

			int rest = l - j, need = a[i] + j + 1; rep(k,0,2) if (k != i) need -= a[k];
			if (rest < need) continue;
			ans += calc(rest, i, b) - calc(need - 1, i, b);
		}
	}
	cout <<ans<<endl;
}