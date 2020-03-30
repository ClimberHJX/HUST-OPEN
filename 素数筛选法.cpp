#include<stdio.h>
#include<math.h>
int prime[10000];//记录发现的素数 
int mark[10001]; //被访问到时标记为1 
int primesize = 0;
void init(){
	for(int i=0;i<=10000;i++){
		mark[i]=0;
	}
	primesize = 0;
	for(int i=2;i<=10000;i++){
		if(mark[i]==1)	//已经被访问到 
			continue;
		prime[primesize++] = i; 
		for(int j=i*i;j<10000;j+=i){
			mark[j] = 1;
		}
	}
} 
 
int main(){
	init();
	int n; 
	while(scanf("%d",&n)!=EOF){
		bool firstOutput = true;
		for(int i=0;prime[i]<n;i++){
			if(prime[i]%10==1){
				if(firstOutput == true){
					printf("%d",prime[i]);
					firstOutput = false;
				}else{
					printf(" %d",prime[i]);
				}	
			}
		}
		if(firstOutput==true){
				printf("-1\n");
			}
		printf("\n");
	}
	return 0;
}
