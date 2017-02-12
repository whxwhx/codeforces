#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
int a[16]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
char s[1010];
int main(){
	int x = 0;
	rep(i,1,15){
		printf("%d\n",a[i]);
		fflush(stdout);
		scanf("%s",s + 1);
		if (s[1] == 'y'){
			if (x) { printf("composite\n"); fflush(stdout); return 0; }
			else x = a[i];
		}
	}
	if (x && x * x <= 100){
		printf("%d\n",x * x); fflush(stdout);
		scanf("%s",s + 1);
		if (s[1] == 'y') { printf("composite\n"); fflush(stdout); return 0; }
	}
	printf("prime\n"); fflush(stdout); return 0;
}