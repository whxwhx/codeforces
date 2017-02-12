#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const LL inf = 20000000000LL;
int main() {
	int a, b, t; scanf("%d%d",&a,&b);
	if (a == 0 || b == 0) { cout <<1LL * a * a - 1LL * b * b<<endl; rep(i,1,a) cout <<'o'; rep(i,1,b) cout <<'x'; cout <<endl; return 0; }
	LL ans = -inf; int mxa = 0;
	if (b == 1) {
		cout <<1LL * a * a - b<<endl;
		rep(i,1,a) cout <<'o'; cout <<'x'; cout <<endl;
		return 0;
	}
	rep(t,2,b) if (a >= t - 1) {
		LL tmp = 1LL * (a - (t - 2)) * (a - (t - 2)) + (t - 2);
		int T = b / t; tmp -= 1LL * T * T * (t - b % t) + 1LL * (T + 1) * (T + 1) * (b % t);
		if (tmp > ans) ans = tmp, mxa = t;
	} else break;
	cout <<ans<<endl;
	t = mxa;
	rep(i,1,t) {
		if (i <= b % t) rep(j,1,b / t + 1) cout <<'x';
		else rep(j,1,b / t) cout <<'x';
		if (i == 1) rep(i,1,a - (t - 2)) cout <<'o'; else if (i < t) cout <<'o';
	}
	cout <<endl;
	return 0;
}
