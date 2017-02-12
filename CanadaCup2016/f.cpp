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
const int N = 100010;
LL ans = 0;
int w[N << 1], l = 0;
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) {
		int a1, b1, a2, b2; cin >>a1>>b1>>a2>>b2;
		if (a1 <= b2 && b1 <= a2) continue;
		else {
			int s1 = a1 + b1, s2 = a2 + b2;
			if (s1 <= s2) {
				if (a1 > b2) ans += a1 - b2;
				else ans += a2 - b1;
			} else w[++l] = -s1, w[++l] = -s2, ans += a1 + a2;
		}
	}
	sort(w + 1, w + l + 1); 
	rep(i,1,l) if (i % 2 == 0) ans += w[i];
	cout <<ans<<endl;
	return 0;
}