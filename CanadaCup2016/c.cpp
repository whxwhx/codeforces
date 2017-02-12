#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define ab(x) ((x) < 0 ? (-(x)) : x)
const int N = 30;
char s[N];
int l[N], r[N], idx[N], idy[N];
char ans[N];
#define pre(x) (x == 1 ? 26 : (x - 1))
bool link(int x, int y) {
	if (ab(idx[x] - idx[y]) <= 1 && ab(idy[x] - idy[y]) <= 1) return true;
	else return false;
}
int main() {
	scanf("%s",s + 1);
	rep(i,1,27) { if (!l[s[i] -'A' + 1]) l[s[i] - 'A' + 1] = i; r[s[i] - 'A' + 1] = i; }
	rep(i,1,13) idx[i] = 1, idy[i] = i;
	rep(i,14,26) idx[i] = 2, idy[i] = 27 - i;
	rep(i,1,26) if (l[i] + 1 < r[i]) {
		rep(x,1,26) {
			int ind = x, xl, xr;
			rep(j,1,27) if (j != r[i]) {
				ans[ind] = s[j];
				if (j == l[i]) xl = ind;
				ind++; if (ind == 27) ind = 1;
			} else xr = ind;
			bool flag = false;
			if (link(pre(xr), xl) && link(xl, xr)) flag = true;
			if (flag) {
				rep(i,1,13) putchar(ans[i]);
				putchar('\n');
				dep(i,26,14) putchar(ans[i]);
				putchar('\n');
				return 0;
			}
		}
	}
	printf("Impossible\n"); return 0;
}