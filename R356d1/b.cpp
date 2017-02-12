#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;

LL L[1100];
int main(){
	LL m; cin >>m;
	LL c = 1; int f = 1; L[1] = 1; L[0] = -1;
	while (c <= m){
		int l = 0, r = 100001;
		while (l + 1 < r){
			int mid = (l + r) >> 1;
			if (3LL * mid * mid + 3LL * mid + mid > c) r = mid; else l = mid;
		}
		c = 1LL * r * r * r + c, f++, L[f] = c;
	}
	if (m == 1) printf("1 1\n"); else {
		printf("%d ",f - 1);
		LL ans = 0;
		dep(i,f - 1,1){
			int l = 1, r = 100001;
			while (l + 1 < r){
				int mid = (l + r) >> 1;
				if (1LL * mid * mid * mid <= m) l = mid; else r = mid;
			}
			if (m - 1LL * l * l * l < L[i - 1]) l--; 
			ans += 1LL * l * l * l, m = min(m - 1LL * l * l * l, 1LL * (l + 1) * (l + 1) * (l + 1) - 1LL * l * l * l - 1);
		}
		cout <<ans<<endl;
	}
}