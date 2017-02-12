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
const LL inf = 1LL << 62;
int n, m, L, S, T, a[N], b[N]; LL c[N];
struct edge { int to, pre; } e[N << 1]; int u[N], l = 1;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }

#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
#define ec c[i >> 1]

typedef pair<LL, int> node;

priority_queue<node> q;
LL dis[N];
void spfa_0(int S) {
	rep(i,1,n) dis[i] = inf;
	q.push(mp(dis[S] = 0, S));
	while (!q.empty()) {
		node t = q.top(); int x = t.second; q.pop();
		if (dis[x] != -t.first) continue;
		reg(i,x) if (ec && dis[x] + ec < dis[v]) 
			dis[v] = dis[x] + ec, q.push(mp(-dis[v], v));
	}
}

int from[N];
void spfa_1() {
	rep(i,1,n) dis[i] = inf;
	q.push(mp(dis[S] = 0, S));
	while (!q.empty()) {
		node t = q.top(); int x = t.second; q.pop();
		if (dis[x] != -t.first) continue;
		reg(i,x) if (dis[x] + (ec ? ec : 1) < dis[v]) 
			from[v] = i, dis[v] = dis[x] + (ec ? ec : 1), q.push(mp(-dis[v], v));
	}
}

void spfa_2() {
	rep(i,1,n) dis[i] = inf;
	q.push(mp(dis[S] = 0, S));
	while (!q.empty()) {
		node t = q.top(); int x = t.second; q.pop();
		if (dis[x] != -t.first) continue;
		reg(i,x) if (dis[x] + (ec ? ec : 1) < dis[v]) 
			dis[v] = dis[x] + (ec ? ec : 1), q.push(mp(-dis[v], v));
	}
}

int main() {
	cin >>n>>m>>L>>S>>T; S++, T++;
	rep(i,1,m) {
		scanf("%d%d%I64d",&a[i],&b[i],&c[i]), a[i]++, b[i]++;
		ins(a[i], b[i]), ins(b[i], a[i]);
	}
	spfa_0(S);
	if (dis[T] < L) { printf("NO\n"); return 0; }
	spfa_1();
	if (dis[T] > L) { printf("NO\n"); return 0; }
	LL rest = L - dis[T];
	for(int x = T; x != S; x = e[from[x] ^ 1].to) if (!c[from[x] >> 1]) c[from[x] >> 1] = -1;
	rep(i,1,m) if (!c[i]) c[i] = L + 1; else if (c[i] == -1) c[i] = 0;
	
	for(int x = T; x != S; x = e[from[x] ^ 1].to){
		if (!c[from[x] >> 1]) {
			c[from[x] >> 1] = L - dis[T] + 1;
			spfa_2();
		}
	}
	printf("YES\n");
	rep(i,1,m) printf("%d %d %I64d\n",a[i] - 1,b[i] - 1,c[i]);
	return 0;
}
