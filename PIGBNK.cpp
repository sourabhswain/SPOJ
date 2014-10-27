//Author:Sourabh..Fractional Knapsack Implementation...
#include<bits/stdc++.h>
using namespace std;
//Start template__sunny_red_devil
#define FOR(i,n) for(i=0;i<n;i++)
#define FU(i,a,n) for(int i=a;i<=n;i++)
#define FD(i,a,n) for(int i=n;i>=a;i--)
#define GI(n) scanf("%d",&n)
#define GII(n,m) scanf("%d %d",&n,&m)
#define PI(n) printf("%d",n)
#define PL(n) printf("%llu",n)
#define PLL(n) printf("%lld",n)
#define GLL(n) scanf("%lld",&n)
#define GL(n) scanf("%llu",&n)
#define PN printf("\n")
#define MAX 10000

//End template__sunny_red_devil
int dp[MAX+1];
int temp[MAX+1];
int p[500],w[500];

int main() {
	
	int t,e,f,n,i,j;
	GI(t);
	while(t--){
		scanf("%d%d%d",&e,&f,&n);
		FOR(i,n){
			scanf("%d%d",&p[i],&w[i]);
		}	
	memset(dp,0,sizeof(dp));
	memset(temp,0,sizeof(temp));
	temp[0]= true;
	
	for(i=0;i<n;i++){
		for(j= w[i];j<=MAX;j++){
			if(temp[j-w[i]] && dp[j]!= 0){
				dp[j]=dp[j]<dp[j-w[i]]+p[i]? dp[j]:dp[j-w[i]]+p[i];
				temp[j] = true;
			}else if(temp[j-w[i]]&&dp[j]==0){
				dp[j]=dp[j-w[i]]+p[i];
				temp[j]=true;
			} 
		}
	}
	
	if(temp[f-e] == false){
		printf("This is impossible.\n");
	}else{
		printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
	}
	}
	return 0;
}
