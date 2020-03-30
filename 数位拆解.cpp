#include<stdio.h>
int a,b;
int main(){
	while(scanf("%d%d",&a,&b)!=EOF){
		int first[11];
		int second[11];
		int sum1=0,sum2=0;
		for(int i=0;a!=0;i++){
			first[i] = a%10;
			a/=10; 
			sum1 += first[i];
		} 
		for(int j=0;b!=0;j++){
			second[j] = b%10;
			b/=10;
			sum2 += second[j];
		}
		printf("%d\n",sum1*sum2);	
	}
	return 0;
}
//或者采用字符串逐个读取的方式 
