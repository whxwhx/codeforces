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
const int N = 200010;
char s[N];
int main() {
	int n, t; scanf("%d%d",&n,&t);
	scanf("%s",s + 1);
	int p0 = 0; rep(i,1,n) if (s[i] == '.') p0 = i;
	if (!p0 || t == 0) { printf("%s\n",s + 1); return 0; }
	int cnt = 0, ans = 0;
	dep(i,n,p0 + 1) {
		if (s[i] == '4' && cnt) {
			cnt++; ans = i - 1; if (cnt == t) cnt = 0;
		} else if (s[i] >= '5') {
			ans = i - 1, cnt = 1; if (cnt == t) cnt = 0;
		} else if (cnt) {
			ans = i; cnt = 0;
		}
	}
	if (ans) {
		s[0] = '0';
		if (ans == p0) ans--;
		s[ans]++;
		while (s[ans] > '9') {
			s[ans] = '0';
			ans--; if (ans == p0) ans--; s[ans]++;
		}
		if (!ans) rep(i,0,p0 - 1) putchar(s[i]);
		else if (ans < p0) rep(i,1,p0 - 1) putchar(s[i]);
		else rep(i,1,ans) putchar(s[i]);
		printf("\n");
	} else printf("%s\n",s + 1);
	return 0;
}