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
const int N = 5010, M = 1000000000 + 7;
char s[N];
short lcp[N][N];
int f[N][N];
inline bool cmp(int a, int l){
	int b = a - l, len = lcp[a - l + 1][b - l + 1];
	swap(a,b);
	if (len >= l) return false; 
	else return s[a - l + len + 1] < s[b - l + len + 1];
}
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s + 1);
	
	lcp[n + 1][n + 1] = 0;
	dep(i,n,1) {
		lcp[i][n + 1] = lcp[n + 1][i] = 0;
		dep(j,n,i)
			if (s[i] == s[j]) lcp[i][j] = lcp[j][i] = lcp[i + 1][j + 1] + 1; 
			else lcp[i][j] = lcp[j][i] = 0;
	}


	rep(i,1,n) f[1][i] = 1;
	rep(i,2,n){
		f[i][0] = 0, f[i][i] = 1;
		rep(j,1,i - 1) {
			if (s[i - j + 1] == '0') f[i][j] = 0;
			else {
				if (cmp(i, j)) f[i][j] += f[i - j][j], f[i][j] %= M;
				else f[i][j] += f[i - j][j - 1], f[i][j] %= M;
			}
		}
		rep(j,1,n) f[i][j] += f[i][j - 1], f[i][j] %= M;
	}

	cout <<f[n][n]<<endl;
}