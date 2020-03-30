#include<stdio.h>
/*一般形式的二分求幂 
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
		for(;b>0;b=b>>1){		//位运算上栽了跟头，没有加b= ,和b++不一样 
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
