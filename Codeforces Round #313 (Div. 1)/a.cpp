#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[7];
int main(){
	rep(i,1,6) scanf("%d",&a[i]);
	cout <<(a[1] + a[2] + a[3]) * (a[1] + a[2] + a[3]) - a[1] * a[1] - a[3] * a[3] - a[5] * a[5]<<endl;
}