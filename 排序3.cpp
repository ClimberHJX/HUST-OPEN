//C����qsort��ʹ��	https://www.cnblogs.com/laizhenghong2012/p/8442270.html
#include<stdio.h>
#include<stdlib.h> 
int compare(const void*a,const void*b){
	return (*(int*)a-*(int*)b);
}
int main(){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		} 
		//qsort����
		qsort(buf,n,sizeof(int),compare);
		//��ӡ
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		} 
		printf("\n");
	}
	return 0;
} 
