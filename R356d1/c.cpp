#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 510;

int n, K; 
char s[N][N];

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int bel[N][N], cnt = 0, sz[N * N];

void dfs(int x, int y){
	bel[x][y] = cnt; sz[cnt]++; if (s[x][y] == 'X') return;
	rep(i,0,3){
		int x1 = x + dx[i], y1 = y + dy[i];
		if (!bel[x1][y1] && s[x1][y1] != 'X') dfs(x1, y1);
	}
}

void init(){
	rep(i,1,n) rep(j,1,n) if (!bel[i][j]) ++cnt, dfs(i, j);
}

int c[N * N];
typedef pair<int, int> node;
#define mp(a,b) make_pair(a,b)
vector<node> v[N];
#define pb(a) push_back(a)
typedef vector<node>::iterator vit;

void add(int c, int t){
	v[max(t - K + 1, 1)].pb(mp(c, 1));
	v[t + 1].pb(mp(c, -1));
}

int main(){
	scanf("%d%d",&n,&K); 
	rep(i,1,n) scanf("%s",s[i] + 1);
	rep(i,1,n) s[i][0] = s[i][n + 1] = 'X';
	rep(i,1,n) s[0][i] = s[n + 1][i] = 'X';
	init(); int ans = 0; rep(i,1,cnt) ans = max(ans, sz[i]);
	rep(i,1,n - K + 1){
		

		rep(j,1,n) v[j].clear();
		rep(j,1,cnt) c[j] = 0;

		rep(j,i,i + K - 1){
			rep(k,1,n){
				add(bel[j][k], k);
				rep(i0,0,3){
					int x1 = j + dx[i0], y1 = k + dy[i0];
					if (s[x1][y1] != 'X') add(bel[x1][y1], k);
				}
			}
		}
		
		int tmp = 0;
		rep(j,1,n - K + 1){
			for(vit it = v[j].begin(); it != v[j].end(); it++) {
				int x = it->first, d = it->second;
				if (!c[x]) tmp += sz[x];
				c[x] += d;
				if (!c[x]) tmp -= sz[x];
			}
			ans = max(ans, tmp);
		}
	}

	printf("%d\n",ans);
	return 0;
}