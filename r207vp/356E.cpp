#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define ok(a,b) (S.find(mp(a,b)) != S.end())
#define rep(i,a,b) for(int i = a, _b = b; i <= _b; i++)
#define dep(i,a,b) for(int i = a, _b = b; i >= _b; i--)
using namespace std;
const int N = 200010, mod[2] = { 998244353, 1000000000 + 7};

typedef pair<int, int> node;
typedef long long LL;

char s[N];
int n, h[2][N], pw[2][N];
int H(int l, int r, int d) {
	l--; return ( (h[d][r] - 1LL * h[d][l] * pw[d][r - l]) % mod[d] + mod[d] ) % mod[d];
}

node hash(int l, int r, bool f) { 
	if (f) l = 2 * n - l + 1, r = 2 * n - r + 1, swap(l, r);
	return mp( H(l, r, 0), H(l, r, 1) ); 
}

LL s0[N], s1[26][N];
int pre[26], nxt[26];

set<node> S;

int ln[N], cr[N];
int main() {
	scanf("%s",s + 1); n = strlen(s + 1); rep(i,1,n) s[2 * n - i + 1] = s[i];
	rep(d,0,1) {
		pw[d][0] = 1; rep(i,1,(n<<1)) pw[d][i] = 27LL * pw[d][i - 1] % mod[d];
		rep(i,1,(n<<1)) h[d][i] = (h[d][i - 1] * 27LL + s[i] - 'a' + 1) % mod[d];
	}
	
	rep(i,1,n) {
		int len = 0;
		dep(j,17,0) {
			len |= 1 << j;
			int l = i - len, r = i + len; 
			if (l < 1 || r > n || hash(l, i, 0) != hash(i, r, 1)) len ^= 1 << j;
		}

		ln[i] = len;
		if (0 < i - len - 1 && i + len + 1 <= n) {
			int cur = len + 1;
			dep(j,17,0) {
				cur += 1 << j;
				int l = i - cur, r = i + cur;
				if (l < 1 || r > n || hash(l, i - len - 2, 0) != hash(i + len + 2, r, 1)) cur -= 1 << j;
			}
			cr[i] = cur;
		} else cr[i] = 0;
	}

	LL ans = 0;
	rep(i,1,n) {
		ans ++; S.insert(mp(i,i));
		rep(c,0,25) if (pre[c]) {
			int L = i - pre[c] - 1;
			int l = i - (L * 2 + 1), r = i + (L * 2 + 1);
			if (l < 1 || r > n || pre[s[i] - 'a'] >= l) continue;
			if (ln[i] >= L * 2 + 1 && ok(l, i - 1))
				ans += 1LL * (r - l + 1) * (r - l + 1), S.insert(mp(l, r)), 
				s0[l] += 1LL * (r - l + 1) * (r - l + 1), s0[r + 1] -= 1LL * (r - l + 1) * (r - l + 1);
		}
		pre[ s[i] - 'a' ] = i;
	}

	//case1
	memset(pre, 0, sizeof(pre));
	rep(i,1,n) {
		int len = ln[i], cur = cr[i];
		if (cur) {
			rep(c,0,25) if (pre[c]) {
				int L = i - pre[c] - 1;
				int l = i - (L * 2 + 1), r = i + (L * 2 + 1);
				int x = i - len - 1, y = i + len + 1;
				if (l < 1 || r > n || pre[s[i] - 'a'] >= l) continue;
				if (len + 1 <= L * 2 + 1 && L * 2 + 1 <= cur && ok(l, i - 1))
					s1[s[x] - 'a'][y] += 1LL * (r - l + 1) * (r - l + 1);
			}
		}
		pre[ s[i] - 'a' ] = i;
	}

	//case2
	rep(i,0,25) nxt[i] = n + 1;
	dep(i,n,1) {
		int len = ln[i], cur = cr[i];
		if (cur) {
			rep(c,0,25) if (nxt[c] <= n) {
				int L = nxt[c] - i - 1;
				int l = i - (L * 2 + 1), r = i + (L * 2 + 1);
				int x = i + len + 1, y = i - len - 1;
				if (l < 1 || r > n || nxt[s[i] - 'a'] <= r) continue;
				if (len + 1 <= L * 2 + 1 && L * 2 + 1 <= cur && ok(i + 1, r))
					s1[s[x] - 'a'][y] += 1LL * (r - l + 1) * (r - l + 1);
			}
		}
		nxt[ s[i] - 'a' ] = i;
	}

	//case3
	memset(pre, 0, sizeof(pre));
	rep(i,1,n) {
		rep(c,0,25) {
			//s[i] -> c
			rep(c1,0,25) if (pre[c1]) {
				int L = i - pre[c1] - 1;
				int l = i - (L * 2 + 1), r = i + (L * 2 + 1);
				if (l < 1 || r > n || pre[c] >= l) continue;
				if (ln[i] >= L * 2 + 1 && ok(l, i - 1)) 
					s1[c][i] += 1LL * (r - l + 1) * (r - l + 1);
			}
		}
		pre[ s[i] - 'a' ] = i;
	}

	LL mx = 0;
	rep(i,1,n) s0[i] += s0[i - 1];
	rep(i,1,n) rep(c,0,25) mx = max(s1[c][i] - s0[i], mx);
	cout <<ans + mx<<endl;
	return 0;
}
