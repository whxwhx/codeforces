#include <iostream>
#include <cstdio>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
int a[10010];
int main() {
	int n; cin >>n; long long ans = 0;
	rep(i,1,n) cin >>a[i];
	rep(l,1,n) {
		rep(r,l,n) {
			int mx = 0;
			rep(i,l,r) mx = max(mx, a[i]);
			ans += mx;
		}
	}
	cout <<ans<<endl;
}