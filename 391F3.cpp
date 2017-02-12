#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 4000010;
typedef long long LL;
LL a[N], ans = 0, b[N], l = 0;

int sl[N], sr[N], tl = 0, tr = 0;

int main() {
	int n, k; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%lld",&a[i]);
	for(int i = 1, j; i < n; i = j + 1) {
		j = i; while (j <= n && a[j + 1] > a[j]) j++;
		if (i == j) continue;
		//add left
		while ( tl && a[ sl[tl] ] > a[i] )
			b[++l] = a[ sl[tl--] ] - a[ sr[tr--] ];
		sl[++tl] = i;
		//add right
		while ( tr && a[ sr[tr] ] < a[j] )
			b[++l] = a[ sl[tl--] ] - a[ sr[tr--] ];
		sr[++tr] = j;
	}
	while (tr) b[++l] = a[ sl[tl--] ] - a[ sr[tr--] ];
	if (k > l) k = l;
	nth_element(b + 1, b + k, b + l + 1);
	rep(i,1,k) ans -= b[i];
	printf("%lld\n",ans);
	return 0;
}