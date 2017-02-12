#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 100010;
struct act{ int l, r, k, id; } a[N], b[N];
inline bool cmp (const act &a, const act &b) { return a.r > b.r || (a.r == b.r && a.l > b.l); }
multiset<act> s; //有重复元素，要用multiset 
inline bool operator < (const act &a, const act &b) { return a.l > b.l; }
int main() {
	int n; scanf("%d",&n); rep(i,1,n) scanf("%d%d",&a[i].l,&a[i].r), a[i].k = i;
	int m; scanf("%d",&m); rep(i,1,m) scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].k), b[i].id = i;
	sort(a + 1, a + n + 1, cmp); sort(b + 1, b + m + 1, cmp); int l1 = 1, l2 = 1;
	while (l1 <= n) {
		if (l2 > m || b[l2].r < a[l1].r) {
			set<act>::iterator it = s.lower_bound(a[l1]);
			if (it == s.end()) { printf("NO\n"); return 0; }
			act tmp = *it; s.erase(it);
			tmp.k--; ans[a[l1].k] = tmp.r; if (tmp.k) s.insert(tmp);
			l1++;
		} else {
			act t = b[l2]; t.r = b[l2].id;
			s.insert(t);
			l2++;
		}
	}
	printf("YES\n"); rep(i,1,n) printf("%d ",ans[i]); printf("\n");
	return 0;
}
