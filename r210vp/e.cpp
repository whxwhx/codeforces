#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 20010;

struct edge { int to, pre, c; } e[N]; int u[N], el = 0;
void ins(int a, int b, int c) { e[++el] = (edge){b, u[a], c}, u[a] = el; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
typedef long long LL;

const LL inf = N * 1000000010LL;
LL d1[N], d2[N];
int T, n;
bool ch[N];
typedef pair<LL, int> node;
priority_queue<node> q;
void dij(int S, LL *d) {
	rep(i,1,n) d[i] = inf; d[S] = 0; q.push(mp(0, S));
	while (!q.empty()) {
		node x = q.top(); q.pop();
		if (x.first != -d[x.second]) continue;
		reg(i,x.second) if (d[x.second] + ec < d[v]) d[v] = d[x.second] + ec, q.push(mp(-d[v], v));
	}
}

int a[N], b[N], l[N], r[N];

int main() {
	int m, k; scanf("%d%d%d",&n,&m,&k);
	int s1, s2; scanf("%d%d%d",&s1,&s2,&T);
	rep(i,1,m) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		ins(a, b, c);
	}
	rep(i,1,k) {
		scanf("%d%d%d%d",&a[i],&b[i],&l[i],&r[i]);
		ins(a[i], b[i], r[i]);
	}
	dij(s1, d1), dij(s2, d2);
	bool flag = true;
	while (flag) {
		flag = false;
		rep(i,1,k) if ( !ch[i] && d1[a[i]] <= d2[a[i]] ) ins(a[i], b[i], l[i]), flag = true, ch[i] = true;
		if (flag) dij(s1, d1), dij(s2, d2);
	}
	if (d1[T] < d2[T]) printf("WIN\n"); else if (d1[T] == d2[T]) printf("DRAW\n"); else { printf("LOSE"); return 0; }
	rep(i,1,k) if ( ch[i] ) printf("%d ",l[i]); else printf("%d ",r[i]); printf("\n"); 
	return 0;
}
