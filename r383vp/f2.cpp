#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 500010;
int f[N], fa[N], r[N], dep[N], tag[N];
map<int, int> g[N];
typedef map<int, int>::iterator mit;
void upd(int &a, int b) { if (b > a) a = b; }
int read() {
	char c = getchar(); int x = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
int main() {
	int n; n = read();
	rep(i,2,n) {
		fa[i] = read(); char c = getchar();
		while (c < 'a' || c > 'v') c = getchar();
		r[i] = c - 'a', dep[i] = dep[fa[i]] + 1;
	}
	rep(i,1,n) tag[i] = 0, g[i][0] = dep[i];
	dep(i,n,2) {
		upd(f[fa[i]], f[i]); tag[i] ^= 1 << r[i];
		if (g[i].size() > g[fa[i]].size()) g[fa[i]].swap(g[i]), swap(tag[i], tag[fa[i]]);

		for(mit it = g[i].begin(); it != g[i].end(); it++) {
			rep(j,0,21) {
				int x = it->first ^ (1 << j) ^ tag[i] ^ tag[fa[i]];
				if (g[fa[i]].find(x) != g[fa[i]].end()) 
					upd(f[fa[i]], g[fa[i]][x] + it->second - (dep[fa[i]] << 1));
			}
		}

		for(mit it = g[i].begin(); it != g[i].end(); it++) {
			int x = it->first ^ tag[i] ^ tag[fa[i]];
			if (g[fa[i]].find(x) != g[fa[i]].end()) 
				upd( f[fa[i]], g[fa[i]][x] + it->second - (dep[fa[i]] << 1) ),
				upd( g[fa[i]][x], it->second);
			else 
				g[fa[i]][x] = it->second;
		}
	}
	rep(i,1,n) printf("%d ", f[i]); printf("\n");
	return 0;
}