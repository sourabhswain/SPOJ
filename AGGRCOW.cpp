//Author:Sourabh..Application of Binary search...(TopCoder tutorial helped)..SPOJ 59
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
#define PII(n,m) printf("%d %d\n",n,m)
#define PL(n) printf("%llu",n)
#define PLL(n) printf("%lld",n)
#define GLL(n) scanf("%lld",&n)
#define GL(n) scanf("%llu",&n)
#define PN printf("\n")
#define MAX 10000
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
int n,c;
//Function to determine whether the number of cows can be placed with a gap of x(mid)
int func(int mid,int array[]){
	int cows =1,temp = array[0];
	FOR(i,n){
		if(array[i]-temp >= mid){
			temp = array[i];
			cows++;	
			if(cows == c) return 1;
		}
	}
	return 0;
}
//Binary search to determine the largest minimum distance....to find the last x(max)
//....yes yes yes yes no no no no....to find the last yes.
int binary_search(int array[]){
	int low=0,high = array[n-1],max= -1;
	while(high > low){
		int mid = (low+high)/2;
		if(func(mid,array) == 1){
			if(mid > max){
			max = mid;
			}
			low = mid+1;
		}else{
			high = mid;
		}	
	}
	return max;
}

int main() {
	
	int t,answer;
	GI(t);
	while(t--){
		GII(n,c);
		int array[n];
		FOR(i,n)
			GI(array[i]);
		sort(array,array+n);
		answer = binary_search(array);
		PI(answer);	
	}
	return 0;
}
