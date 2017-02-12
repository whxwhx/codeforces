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
#define Rep(i,a) for(int i = 0; i < a; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 4000 + 10;
typedef pair<int, int> node;
node a[N];
int l, b[N], cnt[N];
int find(int x){
	int L = 1, R = l + 1;
	while (L + 1 < R){
		int mid = (L + R) >> 1;
		if (b[mid] <= x) L = mid; else R = mid;
	}
	return L;
}
LL ans = 0;
int ans1, ans2;
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&a[i].first,&a[i].second);
		if (a[i].first < a[i].second) swap(a[i].first, a[i].second);
		b[++l] = a[i].second;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + l + 1);
	l = unique(b + 1, b + l + 1) - b - 1;
	rep(i,1,n) a[i].second = find(a[i].second);
	dep(i,n,1){
		cnt[a[i].second]++;
		int t = a[i].first, tmp = n - i + 1;
		for(int j = 1; b[j] <= t && j <= l; j++){
			LL t1 = 1LL * tmp * t * b[j];
			tmp -= cnt[j];
			if (t1 > ans) ans = t1, ans1 = t, ans2 = b[j];
		}
	}
	printf("%lld\n", ans);
	printf("%d %d\n", ans1, ans2);
	return 0;
}