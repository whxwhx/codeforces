#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long LL;
const int N = 2000010;
int cnt[N];
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) { int w; scanf("%d",&w); cnt[w]++; }
	rep(i,0,N - 10) {
		cnt[i + 1] += cnt[i] >> 1;
		cnt[i] = cnt[i] & 1;
	}
	int ans = 0; 
	rep(i,0,N - 10) ans += cnt[i];
	printf("%d\n",ans);
}