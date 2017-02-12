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
const int N = 1000100;
int a3[N], a2[N], a[N];
int main() {
	int n, k; scanf("%d%d",&n,&k);
	cout <<((n - 1) * 6 + 5) * k<<endl;
	rep(i,1,n)
		cout <<((i - 1) * 6 + 1) * k<<' '<<((i - 1) * 6 + 2) * k<<' '<<((i - 1) * 6 + 3) * k<<' '<<((i - 1) * 6 + 5) * k<<endl;
	return 0;
}