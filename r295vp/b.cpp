#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define ch(x,y) (a.find(mp(x, y)) != a.end())
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef pair<int, int> dot;
map<dot, int> a;
priority_queue<int> q0, q1;
const int N = 100010;
int X[N], y[N];
bool ok(int x, int y) {
	rep(d0,-1,1) if (ch(x + d0, y + 1)) {
		bool f = true;
		rep(d1,-1,1) if (x + d0 + d1 != x && ch(x + d0 + d1, y)) { f = false; break; }
		if (f) return false;
	}
	return true;
}
bool del[N], inq[N];
const int mod = 1000000000 + 9;
#define id(x, y) a[mp(x, y)]
int ans[N];

void Del(int x, int y) {
	a.erase(mp(x, y)); int t;
	rep(d0, -1, 1) if (ch(x + d0, y - 1) && (!inq[t = id(x + d0, y - 1)]) && ok(x + d0, y - 1)) 
	{ inq[t] = true; q0.push(t), q1.push(-t); } 
}

int main() {
	int n; cin >>n;
	rep(i,1,n) { cin >>X[i]>>y[i]; a[mp(X[i],y[i])] = i; }
	rep(i,1,n) if (ok(X[i], y[i])) q0.push(i), q1.push(-i), inq[i] = true;
	rep(i,1,n) if (i & 1) {
		int x = q0.top(); q0.pop(); while (del[x]) x = q0.top(), q0.pop(); 
		ans[i] = x; del[x] = true; Del(X[x], y[x]);
	} else {
		int x =-q1.top(); q1.pop(); while (del[x]) x =-q1.top(), q1.pop(); 
		ans[i] = x; del[x] = true; Del(X[x], y[x]);	
	}
	int sum = 0;
	rep(i,1,n) sum = ( 1LL * sum * n % mod + ans[i] - 1 ) % mod;
	cout <<sum<<endl;
	return 0;
}