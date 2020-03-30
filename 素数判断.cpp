#include<stdio.h>
#include<math.h>
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		bool flag = true;
		if(n<=1){
			printf("no\n");
			continue;	
		}
		if(n==2){
			printf("yes\n");
			continue;
		}
		int sqrt = sqrt(n);
		for(int i=2;i<sqrt;i++){
			if(n%i==0){
				printf("no\n");
				flag = false;
				break;
			}
		}
		if(flag == true){
			printf("yes\n");
		}	
	}
	return 0;
} 
