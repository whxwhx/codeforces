#include <iostream>
#include <cstdio>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 100010;
typedef pair<int, int> node;
int n, m, s[N][3], d[N], a[N];
node ans[N]; int l = 0;
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]), a[i]--;
	rep(j,0,1) rep(i,1,n) s[i][j] = (s[i - 1][j] + (a[i] == j));
	rep(s0,1,n) {
		int cur = 0, c[2] = {0,0}; bool flag = true;
		while (cur < n) {
			int x = cur, S[2] = {0,0};
			dep(j,18,0) if (x + (1 << j) <= n){
				int t0 = S[0] + s[x + (1 << j)][0] - s[x][0], t1 = S[1] + s[x + (1 << j)][1] - s[x][1];
				if (t0 < s0 && t1 < s0) S[0] = t0, S[1] = t1, x += (1 << j); //初学者二分经常写错的地方，找第一个满足xxx的地方的时候，应该找最后一个不满足xxx的地方 
			}
			S[0] = s[x + 1][0] - s[cur][0]; S[1] = s[x + 1][1] - s[cur][1];
			cur = x + 1; 
			if (S[0] < s0 && S[1] < s0) { flag = false; break; }
			if (S[0] == s0) c[0]++; if (S[1] == s0) c[1]++;
//			if (s0 == 2) cout <<x<<' '<<S[0]<<' '<<S[1]<<endl;
		}
		if (c[a[n]] <= c[a[n] ^ 1]) flag = false;
		if (flag) ans[++l] = mp(c[a[n]], s0);
	}
	sort(ans + 1, ans + l + 1);
	printf("%d\n",l);
	rep(i,1,l) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
