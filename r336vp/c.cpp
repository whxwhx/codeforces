#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 2000010;
char s[N], t[N];
int p[N];
map<char, char> rev;
int main() {
	int n; scanf("%d",&n); n--;
	scanf("%s",s + 1); scanf("%s",t + 1);
	rev['N'] = 'S', rev['S'] = 'N';
	rev['E'] = 'W', rev['W'] = 'E';
	rep(i,1,n) s[n + i] = rev[t[i]];
	rep(i,1,n/2) swap(s[i], s[n - i + 1]);
	rep(i,2,n * 2) {
		int j = p[i - 1];
		while (j && s[j + 1] != s[i]) j = p[j];
		if (s[j + 1] == s[i]) p[i] = j + 1; else p[i] = 0;
	}
	if (!p[n * 2]) cout <<"YES"<<endl; else cout <<"NO"<<endl;
	return 0;
}