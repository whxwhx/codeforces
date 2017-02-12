#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;
int n, m, c;
const int M = 3010, N = 51, mod = 1000000007; 
int Pow(int a, int b) { int w = 1; for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; return w; }
LL sta[M]; int cnt = 0;
int f[N], pw[310]; 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int a, int b) { int fa = find(a), fb = find(b); f[fa] = fb; }
void dfs(int x, LL S) {
	//check
	rep(i,1,m) f[i] = i;
	rep(i,x + 1,m - 1) if (S >> i & 1) rep(j,1,i) merge(j, m - i + j);
	rep(i,x + 1,m - 1) if (!(S >> i & 1)) { 
		bool flag = true; rep(j,1,i) if (find(j) != find(m - i + j)) { flag = false; break; } 
		if (flag) return;
	}
	//dfs
	if (x == 0) sta[++cnt] = S;
	else dfs(x - 1, S), dfs(x - 1, S | (1LL << x));
}
int F[M], g[310], G[310], inv[310], sum = 0; 
int main() {
	scanf("%d%d%d",&n,&m,&c); dfs(m - 1,0);
	pw[0] = 1; rep(i,1,200) pw[i] = pw[i - 1] * 1LL * c % mod;
	rep(i,0,200) inv[i] = Pow(pw[i], mod - 2);
	dep(s,cnt,1) {
		//count A
		rep(j,1,m) f[j] = j; rep(j,1,m - 1) if (sta[s] >> j & 1) rep(k,1,j) merge(k, m - j + k);
		int L = 0; rep(j,1,m) if (f[j] == j) L++;
		F[s] = pw[L]; rep(j,1,cnt) if ((sta[j] & sta[s]) == sta[s] && s != j) ( F[s] -= F[j] ) %= mod;
		//count B
		g[0] = -1, G[0] = g[0] * 1LL * inv[m] % mod; int ans = 0;
		rep(i,1,n) {
			g[i] = 0; 
			if (i >= m) {
				(g[i] -= 1LL * G[i - m] * pw[i] % mod) %= mod;
				rep(j,1,m - 1) if (sta[s] >> j & 1) (g[i] -= g[i - m + j]) %= mod;
			}
			G[i] = (G[i - 1] + 1LL * g[i] * inv[i + m] % mod) % mod;
			( ans += 1LL * g[i] * pw[n - i] % mod ) %= mod;
		}
		(sum += 1LL * ans * F[s] % mod ) %= mod;
	}
	if (sum < 0) sum += mod; printf("%d\n",sum);
	return 0;
}