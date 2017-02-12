#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 5010, mod = 1000000007;
int f[N][N], s[N][N], n, lcp[N][N];
char S[N];
int h[N], pw[N];

int H(int x, int l) {
	int t = (h[x + l - 1] - h[x - 1] * 1LL * pw[l]) % mod;
	if (t < 0) t += mod;
	return t;
}

bool cmp(int x, int l) {
	int l1 = x - 2 * l + 1, l2 = x - l + 1, len = 0;
	len = min(lcp[l1][l2], l);
	if (len == l) return true; else return S[l1 + len] <= S[l2 + len]; 
}

void upd(int &a, int b) { if (a == -1 || (b > -1 && b < a)) a = b; }

int F[N][N];

void work1() {
	f[0][0] = 1; rep(j,0,n) s[0][j] = 1;
	rep(i,1,n) {
		rep(j,0,n) F[i][j] = -1;
		rep(j,1,i) if (S[i - j + 1] != '0') {
			if (F[i - j][j - 1] > -1) upd(F[i][j], F[i - j][j - 1] + 1);
			( f[i][j] += s[i - j][j - 1] ) %= mod;
			if (i - j >= j && cmp(i,j)){
				( f[i][j] += f[i - j][j] ) %= mod;
				if (F[i - j][j] > -1) upd(F[i][j], F[i - j][j] + 1);
			}
		}
		rep(j,1,n) s[i][j] = (s[i][j - 1] + f[i][j]) % mod;
		rep(j,1,n) upd(F[i][j], F[i][j - 1]); 
	}
	printf("%d\n",s[n][n]);
	int ans = -1;
	rep(j,1,min(n,20)) if (F[n][j] > -1) upd(ans, H(n - j + 1,j) + F[n][j]);
	if (ans > -1) printf("%d\n",ans % mod); else {
		rep(j,21,n) if (F[n][j] > -1){
			printf("%d\n",(H(n - j + 1, j) + F[n][j]) % mod);
			return;
		}
	}
}


int main() {
	scanf("%s",S + 1); n = strlen(S + 1);
	rep(i,1,n) h[i] = (h[i - 1] * 2LL + S[i] - '0') % mod;
	pw[0] = 1; rep(i,1,n) pw[i] = 2LL * pw[i - 1] % mod;
	dep(i,n,1) dep(j,n,1) lcp[i][j] = (S[i] == S[j] ? lcp[i + 1][j + 1] + 1 : 0);
	work1();
	return 0;
}