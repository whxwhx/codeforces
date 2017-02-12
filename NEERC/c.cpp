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
#define Rep(i,a) for(int i = 0; i < a; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 110;
char s[N * 2];
int k[100010], cnt[26], ct[N * 2][26], l;
LL ans = 0, len[65];
void trans(LL &a, LL len, int k){
	a = (a - k) % len; if (a < 0) a += len;
}
void work(int n, LL l, LL r, int c){
	if (n <= 19){
		if (r < l) r += len[0];
		ans += ct[r + 1][c] - ct[l][c];
	} else if ((r + 1) % len[n] == l) ans += (1LL << n) * cnt[c];
	else {
		LL l1, r1, mid = len[n - 1];
		if (l <= r){
			if (l < mid) work(n - 1, l, min(r, mid - 1), c);

			if (r >=  mid) {
				if (l < mid) l1 = mid; else l1 = l; r1 = r;
				l1 -= mid, r1 -= mid;
				trans(l1, len[n - 1], k[n]), trans(r1, len[n - 1], k[n]);
				work(n - 1, l1, r1, c);
			}
		}else{
			if (l >= mid) l1 = 0; else l1 = l;
			if (r >= mid) r1 = mid - 1; else r1 = r;
			work(n - 1, l1, r1, c);
			if (l < mid) l1 = mid; else l1 = l;
			if (r < mid) r1 = len[n] - 1; else r1 = r;
			trans(l1, len[n - 1], k[n]), trans(r1, len[n - 1], k[n]);
			work(n - 1, l1, r1, c);
		}
	}
}

char s[N * 131072 * 2];
void build(){
 	rep(i,1,17){
 		rep(j,1,l){
 			int t1 = l + j - k[i];
 			
 		}
 	}
}
int main(){
	scanf("%s",s + 1);
	l = strlen(s + 1);
	rep(i,1,l) cnt[s[i] - 'a']++;

	int n, m;
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&k[i]);

	len[0] = l;
	LL tmp = 1LL << 60;

	build();
	rep(i,1,n) {
		len[i] = len[i - 1] << 1;
		if (len[i] > tmp) {n = i; break;}
	}
	rep(i,1,2 * l) rep(j,0,25) if (s[i] - 'a' == j) ct[i][j] = ct[i - 1][j] + 1; else ct[i][j] = ct[i - 1][j];

	rep(i,1,m){
		LL l, r; scanf("%I64d%I64d",&l,&r);
		char c = getchar(); while (c < 'a' || c > 'z') c = getchar();
		ans = 0;
		work(n, l - 1, r - 1, c - 'a');
		printf("%I64d\n",ans);
	}
}