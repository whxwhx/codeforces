#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
const int N = 110;
using namespace std;
char s[N][N];
bool ch[N];
int n, m;
int main() {
	scanf("%d%d",&n,&m); int ans = 0;
	rep(i,1,n) scanf("%s",s[i] + 1);
	for(int i = 1; i <= m; i++) {
		bool f = false;
		rep(j,1,n - 1) if (!ch[j] && s[j][i] > s[j + 1][i]) { f = true; break; }
		if (f) { ans ++; continue; }
		rep(j,1,n - 1) if (s[j][i] < s[j + 1][i]) ch[j] = true;
	}
	printf("%d\n",ans);
	return 0;
}
