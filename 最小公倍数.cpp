#include<stdio.h>
//��С������ = m * n / ���Լ��
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
