//Author:Sourabh...0-1 Knapsack ..along with binary search to find the max cost..SPOJ 58
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
#define PII(n,m) printf("%d %d\n",n,m)
#define PL(n) printf("%llu",n)
#define PLL(n) printf("%lld",n)
#define GLL(n) scanf("%lld",&n)
#define GL(n) scanf("%llu",&n)
#define PN printf("\n")
//Math functions
const double pi=acos(-1.0);//pi
const double eps=1e-11;//eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
//End template__sunny_red_devil
int fees[100],fun[100];

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   memset(K,-1,sizeof(K));	
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main() {
	
	int f,n,low,high,mid,max;
	while(true){
	GII(f,n);
	if(f==0 && n==0) break;
	FOR(i,n){
		GII(fees[i],fun[i]);
	}
		max = knapSack(f,fees,fun,n);
		low=0;high=f;

		while(low < high){
			mid= (low+high) >> 1;			
			if(knapSack(mid,fees,fun,n) < max) low = mid+1;
			else high = mid;
		}
		PII(low,max);
	}
	return 0;
}
