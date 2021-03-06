#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 100000 + 10, INF = N * 3 + 1;
int a[N], b[N], c[N], id[N * 3], L = 0;
int find(int x){
	int l = 0, r = L;
	while (l + 1 < r){
		int mid = (l + r) >> 1;
		if (id[mid] >= x) r = mid; else l = mid;
	}
	return r;
}
int n;
typedef pair<int, int> node;
node poi[N * 3];
#define x first
#define y second
#define mp(a,b) make_pair(a,b)
void init(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]), id[++L] = a[i];
	rep(i,1,n) scanf("%d",&b[i]), id[++L] = b[i];
	rep(i,1,n) scanf("%d",&c[i]), id[++L] = c[i];
	sort(id + 1, id + L + 1);
	L = unique(id + 1, id + L + 1) - (id + 1);
	rep(i,1,n) a[i] = find(a[i]);
	rep(i,1,n) b[i] = find(b[i]);
	rep(i,1,n) c[i] = find(c[i]);
	rep(i,1,L) poi[i] = mp(INF,INF);
	rep(i,1,n) if (poi[b[i]].x == INF) poi[b[i]].x = i;
	rep(i,1,n) if (poi[c[i]].y == INF) poi[c[i]].y = i;
}
int vis[N * 3], ans = INF * 3;
//set
//priority_queue
set<node> s;
typedef set<node>::iterator sit;
priority_queue<node> ds;
int lf[N], rg[N], del[N * 7], L1 = 0;
void print(){
	for(sit it = s.begin(); it != s.end(); it++) cout <<(*it).x<<' '<<(*it).y<<endl;
		cout <<endl;
}
void add(node a){
	sit it = s.insert(a).first, r = it, l = it;
	r++, l--;
	if ((*r).y >= a.y) {s.erase(a);/*!!!*/ return;}
	while ((*l).y <= a.y){
		del[rg[(*l).x]] = 1, del[lf[(*l).x]] = 1;
		s.erase(l);
		l = it, l--;
	}
	del[rg[(*l).x]] = 1;
	rg[(*l).x] = lf[a.x] = ++L1;
	ds.push(mp(-((*l).x + a.y), L1));
	
	del[lf[(*r).x]] = 1;
	rg[a.x] = lf[(*r).x] = ++L1;
	ds.push(mp(-(a.x + (*r).y), L1));
}
void calc(int i){
	while ((!ds.empty()) && del[(ds.top()).second]) ds.pop();
	if (ds.empty()) {
		ans  = min(ans, i);//!!!
		return;
	}
	node t = ds.top();
	ans = min(ans, -t.x + i);
}
void work(){
	rep(i,1,L) vis[i] = 0;
	rep(i,1,n) vis[a[i]] = 1;
	s.clear();
	s.insert(mp(0,INF + 1)), s.insert(mp(INF + 1, 0));
	rep(i,1,L) if (!vis[i]) add(poi[i]);//, cout <<id[i]<<endl;
	rep(i,1,L) vis[i] = 0;
	rep(i,1,n) if (!vis[a[i]]) vis[a[i]] = i;
	dep(i,n,1)if (vis[a[i]] == i){
		calc(i);
		add(poi[a[i]]);
	}
	calc(0);
}
int main(){
	init();
	work();
	printf("%d\n",ans);
	return 0;
}