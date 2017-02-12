/*
	对于每个任务/人的分数 有时间限制的问题，可以尝试考虑所有人的[l,r]限制都一样的情形，然后用离散化思想
	分成一块一块的。。。
	比如这题和cf303E
*/
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
const int N = 50010;

int tx;

struct task{
	int t, s, p, num;
}d[N];
bool cmp(const task &a, const task &b){
	return a.t < b.t;
}

struct node { 
	int p, s, f, num; 
};
bool operator <(const node &a,const node &b){
	return a.p < b.p;
}
priority_queue<node> q;
#define mp(a,b) make_pair(a,b)

const LL inf = 1LL << 60;
LL f[N];
void calc(){
	int j = 1;
	rep(i,1,n) if (i == 1 || d[i - 1].t != d[i].t){
		
		while (j <= n && d[j].t <= d[i].t) j++;
		
		LL rest = (j > n ? inf : d[j].t - d[i].t), t = d[i].t;
		rep(k,i,j - 1) q.push((node){d[k].p, d[k].s, 0, k});
		
		while (!q.empty() && rest) {
			node x = q.top();
			if (x.s - x.f <= rest) {
				t += x.s - x.f, rest -= x.s - x.f, x.f = x.s;
				f[x.num] = t - 1;
			}else x.f += rest, rest = 0;
		}
	}
}

typedef pair<int, LL> work;
#define mp(a,b) make_pair(a,b)
work a[N];

bool cmp1(const node &a, const node &b){
	return a.p < b.p;
}

LL ans[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d%d",&d[i].t,&d[i].s,&d[i].p), d[i] = i;
	sort(d + 1, d + n + 1, cmp);
	rep(i,1,n) if (d[i].p == -1) tx = i;
	calc();
	LL T; scanf("%lld\n",&T);
	int txp = 0;
	rep(i,1,n) if (f[i] == T) txp = d[i].p + 1;
	sort(d + 1, d + n + 1, cmp1);

	rep(i,1,n) if (txp == d[i].p && i != tx) txp++;
	sort(d + 1, d + n + 1, cmp);
	rep(i,1,n) if (d[i].p == -1) d[i].p = txp;
	calc();
	printf("%d\n",txp);
	rep(i,1,n) ans[d[i].num] = f[i];
	rep(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}