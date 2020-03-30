#include<stdio.h>
long long A,B;
int m;
int main(){
	while(scanf("%d",&m)!=EOF&& m!=0){
		if(scanf("%lld%lld",&A,&B)==EOF)
			break;
		long long sum = A+B;
		int output[100];
		int i = 0;
		while(sum!=0){
			output[i] = sum%m;
			sum /= m;
			i++; 
		}
		for(int j=i-1;j>=0;j--){
			printf("%d",output[j]);
		}
		printf("\n");
	}
	return 0;
} 
