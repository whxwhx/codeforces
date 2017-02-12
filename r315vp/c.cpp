#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 210 * 2;
#define id(x, d) ((x << 1) | d)
char s[N];
int get(char *s) { return s[0] == 'V'; }

struct edge{ int to, pre; }e[N * N * 8]; int u[N], l = 1;
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
void insert(int a, int b) { ins(a, b); ins(b^1,a^1); }

bool sr[N]; int sta[N];
bool vis[N];
int q[N], n;
bool bfs(int S) {
	memset(vis, false, sizeof(vis));
	int l = 0, r = 1; vis[ q[l] = S ] = true;
	rep(i,id(1,0),id(n,1)) if (sr[i >> 1] && sta[i >> 1] == (i & 1)) vis[ q[r++] = i ] = true;
	while (l < r) {
		int x = q[l++];
		reg(i,x) 
			if (v == (S ^ 1)) return false;
			else if (sr[v >> 1]) { if (sta[v >> 1] != (v & 1)) return false; } 
			else if (!vis[v]) vis[v] = true, q[r++] = v;
	}
	return true;
}

char num[N], ans[N];
int main() {
	scanf("%s",s + 1); int l = strlen(s + 1);
	int m; scanf("%d%d",&n,&m);
	rep(i,1,m) {
		int x1, x2; char s1[3], s2[3];
		scanf("%d%s%d%s",&x1,s1,&x2,s2);
		int t1 = get(s1), t2 = get(s2);
		insert(id(x1, t1), id(x2, t2));
	}
	bool match = true;
	scanf("%s",num + 1);

	int d = get(s + l), mx = 0; rep(j,1,l) if (get(s + j) != d) mx = j;
	if (mx == 0) { 
		rep(j,1,n) sr[j] = true, sta[j] = d; 
		rep(j,1,n) if (!bfs(id(j,d))) { printf("-1\n"); return 0; }
		printf("%s\n",num + 1); return 0;
	}

	rep(i,1,n) {
		bool ok[2] = { bfs(id(i,0)), bfs(id(i,1)) };
		if (match) {
			ans[i] = '\n'; bool flag = bfs(id(i, get(s + num[i] - 'a' + 1)));
			if (flag) {
				sr[i] = true, sta[i] = get(s + num[i] - 'a' + 1);
				rep(j,i+1,n) {
					if (vis[(j << 1) | (d ^ 1)]) {
						if (mx < num[j] - 'a' + 1) { flag = false; break; }
						if (mx > num[j] - 'a' + 1) break;
					} else if (vis[(j << 1) | d]) { if (l > num[j] - 'a' + 1) break; }  
					else {
						if (mx < num[j] - 'a' + 1) {
							if (bfs(id(j, d))) sr[j] = true, sta[j] = d;
							else { flag = false; break; }
						}
						if (l > num[j] - 'a' + 1) break;
					}
				}
				rep(j,i,n) sr[j] = false;
			}

			if (flag) {
				ans[i] = num[i]; sr[i] = true, sta[i] = get(s + num[i] - 'a' + 1);
			} else {
				rep(j,num[i] - 'a' + 2, l) if (ok[get(s + j)]) { ans[i] = 'a' + j - 1; sr[i] = true, sta[i] = get(s + j); break; }
			}
			if (ans[i] == '\n') { printf("-1\n"); return 0; }
			if (ans[i] > num[i]) match = false;
		} else {
			ans[i] = '\n';
			rep(j,1,l) if (ok[get(s + j)]) { ans[i] = 'a' + j - 1; sr[i] = true, sta[i] = get(s + j); break; }
			if (ans[i] == '\n') { printf("-1\n"); return 0; }
		}
	}
	rep(i,1,n) putchar(ans[i]); putchar('\n');
	return 0;
}
