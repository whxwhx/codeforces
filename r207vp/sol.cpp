#include <iostream>
#include <cstdio>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
int a[10010];
long long ans = 0;
bool vis[100010];
int n; 

long long calc(){
	long long ans = 0;
	rep(l,1,n) {
		rep(r,l,n) {
			int mx = 0;
			rep(i,l,r) mx = max(mx, a[i]);
			ans += mx;
		}
	}
	return ans;
}

void dfs(int x) {
	if (x > n) ans = max(ans, calc());
	else rep(i,1,n) if (!vis[i]) {
		vis[ a[x] = i ] = true; dfs(x + 1); vis[i] = false;
	}
}

void dfs2(int x) {
	if (x > n) { if (calc() == ans) { rep(i,1,n) cout <<a[i]<<' '; cout <<endl; } }
	else rep(i,1,n) if (!vis[i]) {
		vis[ a[x] = i ] = true; dfs2(x + 1); vis[i] = false;
	}
}

int main() {
	cin >>n; dfs(1); cout <<ans<<endl; 
	dfs2(1); return 0;
}