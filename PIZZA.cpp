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

int main() {
	int n1,n2;
	char op;
	int n,sum=1,count1=0,count2=0,count3=0,extra=0;
	GI(n);
	FOR(i,n){
		cin>>n1>>op>>n2;
		if(n1==3) count1++;
		else if(n2==4) count2++;
		else if(n2==2) count3++;
	}
	//cout<<count1;
	//cout<<count2;
	//cout<<count3;
	sum = sum+count1+ceil(count3/2.0);
	//cout<< ceil(count3/2.0);
	//cout<<sum;
	extra += count1 + (count3%2)*2;
	//cout<<extra;
	if(count2 >= extra){
		count2 -= extra;
	//	cout<<count2;
		sum += ceil(count2/4.0);
	//	cout<< ceil(count2/4.0);
	}
	PI(sum);
	return 0;
}
