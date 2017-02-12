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

typedef pair<int, int> node;
node mul[N]; int l0 = 0;

priority_queue<int> q[N];

int a[N], val[N];
int main() {
	int k, n, m; cin >>k>>n>>m; 
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) {
		int t, a, b;
		scanf("%d%d%d",&t,&a,&b);
		if (t == 1) val[a] = max(val[a], b); 
		else if (t == 2) q[a].push(b);
		else if (t == 3) mul[++l0] = mp(b, i);
	}
	rep(i,1,n) if (val[i] > a[i]) q[a].push(val[i] - a[i]); else q[a].push(0);
	sort(mul + 1, mul + l0 + 1); rep(i,1,l0/2) swap(mul[i], mul[l0 - i + 1]);
	
	return 0;
}