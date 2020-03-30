#include<stdio.h>
int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		int maxLine = h + (h-1)*2;
		for(int i=0;i<h;i++){
			for(int j=0;j<maxLine;j++){
				if(j<maxLine-h-i*2){
					printf(" ");
				}else{
					printf("*");
				}
			}
			printf("\n");
		}
	}
}
