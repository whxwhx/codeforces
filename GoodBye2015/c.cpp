#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 510;
char s[N][N];
int s1[N][N], s2[N][N];
int main(){
	int h, w; scanf("%d%d",&h,&w);
	rep(i,1,h) scanf("%s",s[i] + 1);
	rep(i,1,h) {
		s1[i][0] = s1[i][1] = 0;
		rep(j,2,w) if (s[i][j] == '.' && s[i][j - 1] == '.'){
			s1[i][j] = s1[i][j - 1] + 1;
		}else s1[i][j] = s1[i][j - 1];
	}
	rep(j,1,w) {
		s2[0][j] = s2[1][j] = 0;
		rep(i,2,h) if (s[i][j] == '.' && s[i - 1][j] == '.'){
			s2[i][j] = s2[i - 1][j] + 1;
		}else s2[i][j] = s2[i - 1][j];
	}
	int q = 0;scanf("%d",&q);
	rep(i,1,q){
		int r1, c1, r2, c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int ans = 0;
		rep(j,r1,r2) ans += s1[j][c2] - s1[j][c1];
		rep(j,c1,c2) ans += s2[r2][j] - s2[r1][j];
		printf("%d\n",ans);
	}
	return 0;
}