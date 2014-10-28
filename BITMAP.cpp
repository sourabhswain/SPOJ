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
#define PI(n) printf("%d ",n)
#define PL(n) printf("%llu",n)
#define PLL(n) printf("%lld",n)
#define GLL(n) scanf("%lld",&n)
#define GL(n) scanf("%llu",&n)
#define PN printf("\n")
#define inf 10000000

//End template__sunny_red_devil

int main() {
	
	int t,n,m,distance = 1;
	char str[200][200];
	GI(t);
	while(t--){
		GII(n,m);
		
		int min_distance[n][m];
		FOR(i,n)
			FOR(j,m){
				min_distance[i][j] = inf;
			}	
				
		queue<int> row_queue;
		queue<int> col_queue;
		
		FOR(i,n){
			scanf("%s",str[i]);
			FOR(j,m){
				if(str[i][j]=='1'){
					min_distance[i][j] = 0;
					row_queue.push(i);
					col_queue.push(j);
				}
			}
		}
	
		int cells_in_this = row_queue.size(),cells_in_next=0;
		while(!row_queue.empty()){
			int row = row_queue.front(); row_queue.pop();
			int col = col_queue.front(); col_queue.pop();
			cells_in_this--;
			
			if(row>0 && (min_distance[row-1][col]>distance)){
				min_distance[row-1][col] = distance;
				row_queue.push(row-1);
				col_queue.push(col);
				cells_in_next++;
			}
			if(col>0 && (min_distance[row][col-1]>distance)){
				min_distance[row][col-1] = distance;
				row_queue.push(row);
				col_queue.push(col-1);
				cells_in_next++;
			}
			if(row<(n-1) && (min_distance[row+1][col]>distance)){
				min_distance[row+1][col] = distance;
				row_queue.push(row+1);
				col_queue.push(col);
				cells_in_next++;
			}
			if(col<(m-1) && (min_distance[row][col+1]>distance)){
				min_distance[row][col+1] = distance;
				row_queue.push(row);
				col_queue.push(col+1);
				cells_in_next++;
			}
		
			if(cells_in_this==0){
				cells_in_this = cells_in_next;
				cells_in_next = 0;
				distance++;
			}
		}
		
		FOR(i,n){
			FOR(j,m){
				PI(min_distance[i][j]);	
			}
		PN;
		}
	}
	return 0;
}
