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
LL n; char s[2];
int main() {
	cin >>n;
	scanf("%s",s), n--;
	LL ans = (n / 4) * 16LL; n %= 4;
	ans += (n % 2) * 7;
	if (s[0] >= 'd') ans += 'f' - s[0] + 1;
	else ans += s[0] - 'a' + 4;
	cout <<ans<<endl;
	return 0;
}