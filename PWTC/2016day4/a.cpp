#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 210, mod = 1000000000 + 7;
typedef long long LL;
int a[N][N], n, m;
int pw(int a, int b) { int w = 1; for(;b;b >>= 1, a = 1LL * a * a % mod) if (b & 1) w = 1LL * w * a % mod; return w;}
void work(int i, int j, int k){
	int f = a[j][k];
	rep(t,k,m) a[j][t] = (a[j][t] - 1LL * f * a[i][t]) % mod, a[j][t] = (a[j][t] + mod) % mod;
}
int main(){
 	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]), a[i][j] = (a[i][j] + mod) % mod;
	int k = 1;
	rep(i,1,m){
		int t = 0;
		rep(j,k,n) if (a[j][i]) { t = j; break; }
		if (!t) continue;
		rep(j,i,m) swap(a[k][j], a[t][j]);
		int f = pw(a[k][i], mod - 2);
		rep(j,i,m) a[k][j] = 1LL * a[k][j] * f % mod;
		rep(j,k + 1,n) if (a[j][i]) work(k, j, i);
		k++; if (k > n) break;
	}
	printf("%d\n",k - 1);
	return 0;
}