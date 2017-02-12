#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 1000010;
int nxt[N], pre[N], ans[N];
void del(int x) { nxt[x][pre] = pre[x], pre[x][nxt] = nxt[x]; }
int main() {
	int n, m; cin >>n>>m; rep(i,1,n) pre[i] = i - 1, nxt[i] = i + 1; nxt[n] = 0;
	rep(i,1,m) {
		int l, r, x; cin >>l>>r>>x;
		for(int i = pre[x]; i && i >= l; i = pre[i]) ans[i] = x, del(i);
		for(int i = nxt[x]; i && i <= r; i = nxt[i]) ans[i] = x, del(i);
	}
	rep(i,1,n) cout <<ans[i]<<' '; cout <<endl; return 0;
}