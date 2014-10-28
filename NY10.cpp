#include<stdio.h>

using namespace std;

int toss_value(char x){
	if(x == 'T') return 0;
	return 1;
}

int scenario(char a,char b,char c){
	return (4*toss_value(a)+2*toss_value(b)+toss_value(c));
}

int main() {
	int p,i=0,num_case;
	scanf("%d",&p);
	while(p--){
		scanf("%d",&num_case);
		char coin_tosses[100];
		scanf("%s",&coin_tosses);
		
		int values[8];
		char first = coin_tosses[0];
		char second = coin_tosses[1];
		char third;
		for(i=0;i<8;i++){
			values[i]=0;
		}
		for(i=2;i<40;i++){
			third = coin_tosses[i];
			values[scenario(first,second,third)]++;
			first = second;
			second = third;
		}
		printf("%d ",num_case);
		for(i=0;i<8;i++){
			printf("%d ",values[i]);
		}
		printf("\n");
	}	
	return 0;
}
