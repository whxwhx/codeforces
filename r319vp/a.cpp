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
int ans[N], l = 0;
int main() {
	int n; scanf("%d",&n);
	rep(i,2,n) {
		bool flag = true; rep(j,2,i - 1) if (i % j == 0) flag = false;
		if (flag) { int b = i; while (b <= n) ans[++l] = b, b *= i; }
	}
	cout <<l<<endl;
	rep(i,1,l) cout <<ans[i]<<' '; cout <<endl;
}