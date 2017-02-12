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
const int N = 200010;
typedef pair<int, int> node;
priority_queue<node> q;
int n, m, t[N], st[N], cur[N];
LL s[1010][1010], s0[1010], s1[1010], s2[1010];
void init() {
	st[1] = 0; q.push(mp(-t[1], 1));
	rep(i,2,n) {
		int x = q.top().second; q.pop();
		st[i] = cur[i] = (cur[x] += t[x]);
		q.push(mp(-(cur[x] + t[x]), x));
		q.push(mp(-(cur[i] + t[i]), i));
	}
	rep(i,1,n) s0[t[i]]++, s[t[i]][st[i] % t[i]] ++, s1[t[i]] += st[i], s2[t[i]] += st[i] % t[i];
	rep(i,1,1000) rep(j,1,i - 1) s[i][j] += s[i][j - 1];
}

LL calc(LL n) {
	LL ans = 0;
	rep(t,1,1000)
		ans += (n * s0[t] - s1[t] - ( (n % t) * s0[t] - s2[t] + t * (s0[t] - s[t][n % t]))) / t;
	return ans + 1;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&t[i]);
	sort(t + 1, t + n + 1); init();	
	rep(i,1,m) {
		int a; scanf("%d",&a); a++; 
		if (a <= n) printf("%d\n",st[a]);
		else {
			LL ans = 0;
			dep(j,40,0) if (calc(ans | (1LL << j)) < a) ans |= 1LL << j;
			ans++; cout <<ans<<endl;
		}
	}
	return 0;
}