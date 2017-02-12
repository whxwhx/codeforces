#include <iostream>
#include <cstdio>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < a; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const int N = 5000010, mod = 1000000000 + 7;
int f[N], n, k, a[N]; LL L;
int &F(int a, int b) { return f[a * (k + 1) + b]; }

int b[N];
int main() {
	cin >>n>>L>>k; Rep(i,n) scanf("%d",&a[i]), b[i] = a[i];	
	sort(a, a + n); 
	F(0,0) = 1;
	rep(j,1,k) {
		int s = 0, t = 0;
		Rep(i,n) {
			while (t < n && a[t] <= a[i]) ( s += F(t,j - 1) ) %= mod, t++;
			( F(i,j) = s ) %= mod;
		}
	}
	int l = L % n;
	sort(b, b + l); int ans = 0;
	rep(j,1,k) {
		LL cnt = L / n - (j - 1); if (cnt < 0) break;
		int s = 0; Rep(i,n) ( s += F(i, j) ) %= mod;
		( ans += cnt % mod * s % mod) %= mod;
		s = 0; int sum = 0, t = 0;
		Rep(i,l) {
			while (t < n && a[t] <= b[i]) ( s += F(t,j - 1) ) %= mod, t++;
			(sum += s) %= mod;
		}
		if (L >= l + n * (j - 1)) ( ans += sum ) %= mod;
	}
	if (ans < 0) ans += mod; cout <<ans<<endl;
	return 0;
}