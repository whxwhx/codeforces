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
const int N = 100010;
int f[N], h[N], g[N];
int main() { 
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&h[i]);
	rep(i,1,n) f[i] = h[i], f[i] = min(f[i], f[i - 1] + 1);
	dep(i,n,1) g[i] = h[i], g[i] = min(g[i], g[i + 1] + 1);
	int ans = 0; rep(i,1,n) ans = max(ans, min(f[i], g[i]));
	printf("%d\n",ans);
}