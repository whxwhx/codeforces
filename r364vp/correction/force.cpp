#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 10010;
int f[N][N];
char s[N];
int main() {
	int n; scanf("%d",&n); scanf("%s",s + 1);
	rep(len,1,n) {
		rep(i,1,n) {
			int j = i + len - 1; if (j > n) break;
			f[i][j] = 1;
			dep(k,len - 1,1) {
				bool flag = true;
				rep(t,1,k) if (s[i + t - 1] != s[j - k + t]) { flag = false; break; }
				if (flag) { f[i][j] = f[i][i + k - 1] + 1; break; }
			}
		}
	}
	int ans = 0; 
	rep(i,1,n) rep(j,1,n) ans = max(ans, f[i][j]);
	printf("%d\n",ans);
	return 0;
}