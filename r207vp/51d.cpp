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

const int N = 510;
int l; char s[N]; int a[N], b[N], n = 0;

int main() {
	scanf("%s",s + 1); l = strlen(s + 1);
	rep(i,1,l) a[i] = s[i] - '0';
	while (l > 0) {
		b[++n] = a[l] & 1;
		rep(i,1,n) {
			if (vis[i]) 
		}
	}
}