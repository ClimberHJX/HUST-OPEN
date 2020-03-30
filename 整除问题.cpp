#include<stdio.h>
#include<math.h>

int prime[1000];
int mark[1001];
int primeSize = 0;
void init(){
	for(int i =0;i<1001;i++){
		mark[i] = 0;
	}
	for(int i=2;i<=1000;i++){
		if(mark[i]==1)
			continue;
		mark[i] = 1;
		prime[primeSize++] = i;
		for(int j=i*i;j<1000;j=j+i){
			mark[j] = 1;
		}
	}
}


int main(){
	init();	
	int n,a;
	while(scanf("%d%d",&n,&a)!=EOF){
		
		int cnt1[primeSize] = {0};
		int cnt2[primeSize] = {0};
		for(int i=0;i<primeSize;i++){
			int t = n;
			while(t!=0){
				cnt1[i] += t/prime[i];
				t = t/prime[i];
			}
		}
		
		int ans = 123123123;
		for(int i=0;i<primeSize;i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a /= prime[i];
			}
			
			if(cnt2[i]==0) continue;
			if(cnt1[i] / cnt2[i] < ans){
				ans = cnt1[i] / cnt2[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
