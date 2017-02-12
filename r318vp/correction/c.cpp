#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 200010;

struct edge { int to, pre; }e[N]; int u[N], l = 1;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

#define x first
#define y second
#define mp(a,b) make_pair(a,b)
typedef pair<int, int> sta;
bool g[N], G[N], v_g[N], v_G[N];
int d[N];

bool _G(int x, int id) {
//	cout <<"G x:"<<x<<" f:"<<f<<endl;
	if (d[x] > 3) return false;
	if (v_G[id]) return G[id]; else v_G[id] = true;
	reg(i,x) if (i != (id ^ 1) && (d[v] == 3 || !_G(v, i))) return G[id] = false;
	return G[id] = true;
}

bool _g(int x, int id) {
//	cout <<"g x:"<<x<<" f:"<<f<<endl;
	if (v_g[id]) return g[id]; else v_g[id] = true;
	int cnt = 0;
	reg(i,x) if (i != (id ^ 1) && !_G(v, i)) {
		cnt++; if (cnt >= 2) return g[id] = false;
		if (!_g(v, i)) return g[id] = false;
	}
	return g[id] = true;
}

int main() {
	int n; scanf("%d",&n);
	rep(i,1,n - 1) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b), ins(b, a); d[a]++, d[b]++;
	}

	bool chain = true;
	rep(i,1,n) if (d[i] > 2) { chain = false; break; }
	if (chain) { printf("Yes\n"); return 0; }

	rep(x,1,n) if (d[x] > 2) {
		int cnt = 0; reg(i,x) if (!_G(v, i)) cnt++;
		if (cnt <= 2) {
			bool flag = true;
			reg(i,x) if (!_G(v, i) && !_g(v, i))
			{ flag = false; break; }
			if (flag) { printf("Yes\n"); return 0; }
		}
	}
	printf("No\n");
	return 0;
}