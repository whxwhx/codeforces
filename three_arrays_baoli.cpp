#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N = 100000 + 10;
int a[N], b[N], c[N], vis[N];
int main(){
	int n; cin >>n;
	rep(i,1,n) vis[i] = 2;
	rep(i,1,n) cin >>a[i], vis[a[i]] = 1;
	rep(i,1,n) cin >>b[i], vis[b[i]] = 1;
	rep(i,1,n) cin >>c[i], vis[c[i]] = 1;
	int ans = 3 * n;
	rep(i,0,n){
		rep(j,0,n){
			rep(k,0,n){
				rep(t,1,n) if (vis[t] == 1) vis[t] = 0;
				rep(t,1,i) vis[a[t]] = 1;
				rep(t,1,j) vis[b[t]] = 1;
				rep(t,1,k) vis[c[t]] = 1;
				bool flag = 1;
				rep(t,1,n) if (!vis[t]) flag = 0;
				if (flag) ans = min(ans, i + j + k);
			}
		}
	}
	cout <<ans<<endl;
	return 0;
}