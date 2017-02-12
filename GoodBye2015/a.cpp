#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
char s[20];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s); scanf("%s",s);
	if (s[0] == 'm'){
		if (n <= 29) cout <<12<<endl;
		else if (n == 30) cout <<11<<endl;
		else if (n == 31) cout <<7<<endl;
	} else {
		n %= 7;
		int t = 4, ans = 0;
		rep(i,1,366){
			t = (t + 1) % 7;
			if (n == t) ans++;
		}
		cout <<ans<<endl;
	}
}