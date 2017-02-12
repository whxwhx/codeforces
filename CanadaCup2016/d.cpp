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
priority_queue<LL> q;
const int N = 300010;
typedef pair<LL, LL> node;
node a[N];
int main() {
	int n; scanf("%d",&n); LL tot = 0;
	rep(i,1,n) {
		LL t, w; cin >>t>>w;
		if (i != 1) a[i] = mp(-t, w + 1 - t); else tot = t, a[i] = mp(-t, 1LL << 62);
	}
	sort(a + 1, a + n + 1);
	int j = 1, cnt = 0, ans = n; LL tmp = tot;
	rep(i,1,n) if ((-a[i].first) <= tot) {
		while (j <= n && (-a[j].first) > (-a[i].first)) q.push(-a[j].second), j++;
		while (!q.empty() && tot + q.top() >= (-a[i].first)) tot += q.top(), cnt++, q.pop();
		ans = min((i - ((-a[i].first) < tmp)) - cnt, ans);
	}

	while (j <= n) q.push(-a[j].second), j++;
	while (!q.empty() && tot + q.top() >= 0) tot += q.top(), cnt++, q.pop();
	ans = min(n - cnt, ans);

	printf("%d\n",ans);
	return 0;
}