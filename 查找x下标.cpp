#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int x;
		bool find = false;
		scanf("%d",&x);
		for(int i=0;i<n;i++){
			if(x==a[i]){
				find = true;
				printf("%d\n",i);
				break;
			}
		}
		if(find==false){
			printf("-1\n");
		}
	}
} 
