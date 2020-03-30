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
		int ansPrime[30];	//按顺序保存分解出的对应的素因数
		int ansSize = 0;
		int ansNum[30];	// 保存分解出的素因数对应的幂指数
		for(int i=0;i<primesize;i++){
			if(n%prime[i]==0){
				ansPrime[ansSize] = prime[i];
			}
			ansNum[ansSize] = 0;
			while(n%prime[i]==0){
				ansNum[ansSize] ++;
				n/=prime[i];
			}
			ansSize++;
			if(n==1) break;
		} 
		
		// 若测试完2到100000内所有素因数, n仍未被 分解至1, 则剩余的因数一定100000的素因数
		if(n!=1){
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;			
		}
		
		int ans = 0;
		for(int i=0;i<ansSize;i++){
			ans += ansNum[i];
		}
		printf("%d",ans);
	}
	return 0;
}
