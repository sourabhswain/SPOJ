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
#define PI(n) printf("%d\n",n)
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
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T gcd(T a,T b)
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
//End template__sunny_red_devil
int a[2000];
int result[2000][2000]; int n;

int maximize(int i,int j){
	if(result[i][j] != -1){
		return result[i][j];
	}
	int day;
	day = n-j+i;
	
	if(i==j) return day*a[i];
	
	result[i][j] = max(day*a[i] + maximize(i+1,j), day*a[j] + maximize(i,j-1));
	return result[i][j];
}

int main() {
	
	GI(n);
	FOR(i,n){
		GI(a[i]);
	}
	FOR(i,n)
		FOR(j,n){
			result[i][j] = -1;
		}
	PI(maximize(0,n-1));
	return 0;
}
