#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)

const int N = 100010 * 19;

int ch[N][2], s[N], l = 1, rt = 1;

map<LL, int> cnt;

int main() {
	int t; scanf("%d",&t);
	rep(i,1,t) {
		char op[10]; scanf("%s",op);
		LL a; scanf("%I64d",&a);
		if (op[0] == '+') {
			LL t = 0, tmp = 1;
			rep(i,1,18) t = t + (a & 1) * tmp, tmp *= 10, a /= 10;
			cnt[t]++;
		} else if (op[0] == '-') {
			LL t = 0, tmp = 1;
			rep(i,1,18) t = t + (a & 1) * tmp, tmp *= 10, a /= 10;
			cnt[t]--;
		} else if (op[0] == '?') {
			printf("%d\n",cnt[a]);
		}
	}
	return 0;
}
