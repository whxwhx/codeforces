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
const int N = 200010;
char s[N];
int main() {
	int n; scanf("%d",&n);
	scanf("%s",s + 1);
	int ans = 0;
	rep(i,1,n) if (s[i] == '<') ans++; else break;
	dep(i,n,1) if (s[i] == '>') ans++; else break;
	printf("%d\n", ans);
	return 0;
}