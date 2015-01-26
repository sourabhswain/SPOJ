#include<bits/stdc++.h>
#include<iomanip>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair< int ,int > pii;
#define SIZE(X) ((int)(X.size()))
#define X first
#define Y second
#define LENGTH(X) ((int)(X.length()))
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])
typedef long long int int64;
typedef unsigned long long uLL;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FU(i,a,n) for(int i=a;i<=n;i++)
#define FD(i,a,n) for(int i=n;i>=a;i--)
#define GI(n) scanf("%d",&n)
#define GS(n) scanf("%s"&s)
#define GII(n,m) scanf("%d %d",&n,&m)
#define PI(n) printf("%d\n",n)
#define PII(n,m) printf("%d %d\n",n,m)
#define PL(n) printf("%I64d\n",n)
#define PLL(n) printf("%I64d\n",n)
#define GLL(n) scanf("%I64d",&n)
#define GL(n) scanf("%I64d",&n)
#define PN printf("\n")
#define MAX 27

const int px[4] = {1,0,-1,0};
const int py[4] = {0,-1,0,1}, inf = 0x3f3f3f3f;
int w,h,dirty;
int dis[1<<10][MAX][MAX];
char maze[MAX][MAX];

bool within(int x,int y){
	return x>=0 && x<h && y>=0 && y< w;
}

int bfs(int x,int y){
	int s,nx,ny,ns,ans=inf;
	queue<int> q;
	dis[s=0][x][y]=0;
	q.push(x);
	q.push(y);
	q.push(s);
	while(!q.empty()){
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		s = q.front(); q.pop();
		for(int i=0;i<4;i++){
			nx = x+px[i];
			ny = y+py[i];
			ns = s;
			if(within(x,y) && maze[nx][ny] != 'x'){
				if(isupper(maze[nx][ny])) ns |= (1<<(maze[nx][ny]-'A'));
				if(dis[ns][nx][ny] > dis[s][x][y] + 1){
					dis[ns][nx][ny] = dis[s][x][y]+1;
					if(ns == (1<<dirty)-1) ans = min(ans,dis[ns][nx][ny]);
					q.push(nx);
					q.push(ny);
					q.push(ns);
				}
			}
		}
	}
	return ((ans<inf) ? ans:-1);
}

int main(){
	//ios::sync_with_stdio(false);
	int sx,sy;
	while((scanf("%d %d",&w,&h)) == 2 &&(w+h)){
	//cin>>w>>h;
	FOR(i,h){
			scanf("%s ",maze[i]);
			FOR(j,w){
			if(maze[i][j] == 'o') sx=i,sy=j;
			if(maze[i][j] == '*') maze[i][j] = 'A' + dirty++;
			}	
	}
	for(int k=0;k< (1<<dirty);k++){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				dis[k][i][j] = inf;			
			}
		}
	}
	//cout<<bfs(sx,sy)<<endl;
	printf("%d\n", bfs(sx, sy));
	} 
 return 0;
}
