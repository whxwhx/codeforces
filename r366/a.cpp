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
const int N = 400010;
vector<int> a[N];
bool vis[N];
int t = 0, cnt = 0;
int main() {
	int n, q, cur = 0; scanf("%d%d",&n,&q);
	rep(i,1,q) {
		int op; scanf("%d",&op);
		if (op == 1) {
			int x; scanf("%d",&x);
			a[x].pb(++t), cnt++;
		} else if (op == 2) {
			int x; scanf("%d",&x);
			int l = a[x].size();
			rep(i,0,l - 1) if (!vis[a[x][i]]) vis[ a[x][i] ] = true, cnt--;
			a[x].clear();
		} else {
			int t; scanf("%d",&t);
			rep(i,cur + 1,t) if (!vis[i]) vis[i] = true, cnt--;
			cur = max(cur, t);
		}
		printf("%d\n",cnt);
	}
	return 0;
}