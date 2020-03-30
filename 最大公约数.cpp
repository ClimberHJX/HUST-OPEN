#include<stdio.h>
int m,n;
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		do{
			int tmp = m % n;
			m = n;
			n = tmp;
		} while(m!=0&&n!=0);
		printf("%d\n",m);
	}
	return 0;
} 
