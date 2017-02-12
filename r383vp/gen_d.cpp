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
const int N = 500000;
int main() {
	cout <<N<<endl; 
	cout <<1<<' '<<'a'<<endl;
	cout <<1<<' '<<'a'<<endl;
	char c[2] = {'a', 'v'}; int s[2] = {0,0}, l[2] = {2, 2};
	rep(i,4,N) {
		cout <<(i >> 1)<<' '<<c[i & 1]<<endl;
		s[i & 1]++; 
		if (s[i & 1] == l[i & 1]) {
			l[i & 1] *= 2, s[i & 1] = 0;
			if (i & 1) c[i & 1]--; else c[i & 1]++;
		}
	}
}
