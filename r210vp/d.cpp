#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
typedef long long LL;
using namespace std;
int d[11000], l = 0;
int n, m, p, rt, bl;

int pw(int a, int b) { int w = 1; for(;b;b >>= 1, a = 1LL * a * a % p) if (b & 1) w = 1LL * w * a % p; return w; }

bool check(int x) {
	rep(i,1,l) if (pw(x, (p - 1) / d[i]) == 1) return false;
	return true;
}

void findrt() { 
	int t = p - 1;
	for(int i = 2; i * i <= t; i++) if (t % i == 0) {
		d[++l] = i; while (t % i == 0) t /= i;
	}
	if (t > 1) d[++l] = t;
	rep(i,2,p) if (check(i)) { rt = i; break; } 
}

const int N = 100010;

int a[N], b[N];

int gcd(int a, int b) { 
	if (a == 0 || b == 0) return a | b;
	return gcd(b, a % b);
}

int f[N];
bool cov[N];

int find(int x) {
	int L = 0, r = l;
	while (L + 1 < r) {
		int mid = (L + r) >> 1;
		if (d[mid] >= x) r = mid; else L = mid;
	}
	return r;
}

int main() {
	scanf("%d%d%d",&n,&m,&p);
	l = 0;
	for(int i = 1; i * i <= p - 1; i++) if ((p - 1) % i == 0) {
		d[++l] = i; if (i * i < (p - 1)) d[++l] = (p - 1) / i;
	}
	sort(d + 1, d + l + 1);
	rep(i,1,n) { 
		int x; scanf("%d",&x); 
		if (x == 1) a[i] = 0;
		else {
			rep(j,1,l) if (pw(x, d[j]) == 1) { a[i] = (p - 1) / d[j]; break; }
		}
	}
	rep(i,1,m) scanf("%d",&b[i]), b[i] %= p - 1;
	int g = 0; rep(i,1,m) g = gcd(g, b[i]);
	dep(i,l,1) { f[i] = (p - 2) / d[i]; rep(j,i + 1,l) if (d[j] % d[i] == 0) f[i] -= f[j]; }
	rep(i,1,n) if (1LL * a[i] * g % (p - 1)) {
		int x = gcd(1LL * a[i] * g % (p - 1), p - 1);
		cov[find(x)] = true;
	}
	rep(i,1,l) if (cov[i]) rep(j,i+1,l) if (d[j] % d[i] == 0) cov[j] = true;
	int ans = 1;
	rep(i,1,l) if (cov[i]) ans += f[i];
	printf("%d\n",ans);
	return 0;
}
