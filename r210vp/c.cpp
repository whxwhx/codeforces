#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 2010, mod = 1000000000 + 7;
int n, k, f[N][N];
char s[N]; int a[N];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s + 1); rep(i,1,n) a[i] = s[i] - 'a' + 1;
	f[0][0] = 1;
	rep(i,1,n) {
		rep(j,0,k) f[i][j] = 1LL * f[i - 1][j] * a[i] % mod;
		int delta;
		for(int s = i - 1; s >= 0 && (delta = (i - s) * (n - i + 1)) <= k; s--) {
			rep(j,0,k) if (j + delta <= k) {
				int tmp = f[s][j];
				if (s > 0) tmp = (tmp - f[s - 1][j]) % mod;
				( f[i][j + delta] += 1LL * tmp * (26 - a[i]) % mod ) %= mod;
			} else break;
		}
	}
	printf("%d\n",(f[n][k] + mod) % mod);
	return 0;
}
