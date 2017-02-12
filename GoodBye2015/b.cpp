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
int main(){
	LL l, r, ans = 0; cin >>l>>r;
	rep(i,2,61){
		LL t = (1LL << i) - 1;
		dep(j, i - 2, 0) {
			LL tmp = t ^ (1LL << j);
			if (l <= tmp && tmp <= r) ans++;
		}
	}
	cout <<ans<<endl;
}