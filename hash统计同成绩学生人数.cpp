#include<stdio.h>
int N;
int main(){
	while(scanf("%d",&N)!=EOF&&N!=0){
		int hash[101] = {0};
		for(int i=0;i<N;i++){
			int x;
			scanf("%d",&x);
			hash[x]++;
		}
		int x;
		scanf("%d",&x);
		printf("%d\n",hash[x]);
	}
	return 0;
} 
