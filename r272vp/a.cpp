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
const int mod = 1000000000 + 7;
typedef long long LL;
typedef unsigned long long uLL;
int main() {
	int a, b; scanf("%d%d",&a,&b);
	int sa = 0; rep(i,1,a) sa = (sa + i) % mod;
	int sb = 0; rep(i,0,b - 1) sb = (sb + i) % mod;
	int ans = ( 1LL * a * sb + 1LL * b * sa % mod * sb % mod) % mod;
	if (ans < 0) ans += mod;
	printf("%d\n",ans);
}