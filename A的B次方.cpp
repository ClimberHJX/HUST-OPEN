#include<stdio.h>
/*һ����ʽ�Ķ������� 
int pow(int x,int n){
	int res = 1;
	if(n==0)
		return 1;
		
	for(;n>0;n>>2){
		if(n%2==1)	res *= x;
		x *= x;
	}
	return res;
}
*/


int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && a!=0 && b!=0 ){
		int res = 1;
		for(;b>0;b=b>>1){		//λ���������˸�ͷ��û�м�b= ,��b++��һ�� 
			if(b%2 == 1){
				res *= a;
				res %= 1000;
			}
			a *= a;
			a %= 1000;
		}
		printf("%d\n",res);
	} 
	return 0;	
}
