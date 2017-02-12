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
const int N = 100010, M = 1000010;
int a[N], b[N];
int d[M], f[M];
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
	rep(i,1,n) d[a[i]] = b[i];
	int ans = 0;
	rep(i,0,M - 10) if (!d[i]) f[i] = f[i - 1]; else {
		if (i - d[i] - 1 < 0) f[i] = 1;
		else f[i] = f[i - d[i] - 1] + 1;
		ans = max(ans, f[i]);
	}
	printf("%d\n",n - ans);
	return 0;
}