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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int N = 1000010;
char a[N], b[N];

int cnt[2][27];

int main() {
	LL n, m; cin >>n>>m;
	scanf("%s",a + 1); scanf("%s",b + 1); 
	int la = strlen(a + 1), lb = strlen(b + 1), g = gcd(la, lb); LL lcm = la / g * 1LL * lb;
	LL t = n * la / lcm, ans = 0;
	rep(j,1,g) {
		rep(i,0,25) cnt[0][i] = cnt[1][i] = 0;
		for(int i = j; i <= la; i += g) cnt[0][a[i] - 'a']++;
		for(int i = j; i <= lb; i += g) cnt[1][b[i] - 'a']++;
		rep(i,0,25) ans += 1LL * cnt[0][i] * (lb / g - cnt[1][i]);
	}
	ans = ans * t; cout <<ans<<endl;
	return 0;
}