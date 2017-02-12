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

int n, c, s, a[N];

struct edge{ int to, pre, c; }e[N * 2]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

bool vis[N];

int sz[N], s[N], sum, rt;

void getrt(int x, int f){
	sz[x] = 1, s[x] = 0;
	reg(i,x) if (!vis[v] && v != f) getrt(v, x), s[x] = max(s[x], sz[v]);
	s[x] = max(s[x], sum - sz[x]); if (s[x] < s[rt]) rt = x;
}

int ans;

LL dis[N], f[N];
const LL INF = 1LL << 61;

typedef pair<LL, int> node;

priority_queue<node> q;

int mxa = 0, ex = 0, ey = 0;

int calc(int x){
	rep(i,1,n) dis[i] = INF; dis[x] = 0;
	reg(i,x) {
		f[v] = 0; dis[v] = ec; q.push(mp(-dis[v], v)); int t = v;
		while (!q.empty()){
			int x = q.top().second; LL y = q.top().first; q.pop();
			if (dis[x] < y) continue;
			//dp x
			f[t] = max(f[t] + 1, dis[x]) + a[x] - 1; 
			//extend
			reg(i,x) if (dis[v] > dis[x] + ec)
				dis[v] = dis[x] + ec, q.push(mp(-dis[v], v));
		}
	}

	reg(i,x) if (f[v] > f[mxa]) mxa = v;
	ex = x, ey = mxa; return mxa;
}

void work(int x){
	int t = calc(x); vis[x] = true;

	if (vis[t]) return;

	int tmp = sum - sz[x];
	reg(i,x) if (v == t){
		sum = sz[v] < sz[x] ? sz[v] : tmp; rt = 0; getrt(v, x);
		work(rt);
	}
}

int main(){
	scanf("%d%d%d",&n,&c,&s); 
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n - 1){
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		ins(a, b, c), ins(b, a, c);
	}

	s[rt = 0] = sum = n;
	getrt(1, 0); work(rt);

	return 0;
}