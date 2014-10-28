//Author:Sourabh
#include<bits/stdc++.h>
using namespace std;
//Start template__sunny_red_devil
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
typedef long long LL;
typedef long long int int64;
typedef unsigned long long uLL;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FU(i,a,n) for(int i=a;i<=n;i++)
#define FD(i,a,n) for(int i=n;i>=a;i--)
#define GI(n) scanf("%d",&n)
#define GII(n,m) scanf("%d %d",&n,&m)
#define PI(n) printf("%d",n)
#define PL(n) printf("%llu",n)
#define PLL(n) printf("%lld\n",n)
#define GLL(n) scanf("%lld",&n)
#define GL(n) scanf("%llu",&n)
#define PN printf("\n")
//End template__sunny_red_devil

long long solve(int x,int y){
	int n = x-1;
	int r=y-1,i=0;
	long long answer =1;
	if(r > n/2){
		r = n-r;
	}
	for(i=0;i<r;i++){
		answer *= (n-i);
		answer /= (i+1);
	}
	return answer;
}

int main() {
	
	int t,n,m;
	GI(t);
	while(t--){
		GII(n,m);
		PLL(solve(n,m));	
	}
	return 0;
}
