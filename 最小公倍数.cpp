#include<stdio.h>
//最小公倍数 = m * n / 最大公约数
int m,n;
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		int a = m,b = n; 
		do{
			int tmp = m % n;
			m = n;
			n = tmp;
		} while(m!=0&&n!=0);
		printf("%d\n",a*b/m);
	}
	return 0;
}  
