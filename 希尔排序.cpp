#include<stdio.h>

void ShellSort(int a[],int n){
	if(n==0)
		return;
	int gap,j,cur,i;
	for(gap = n/2;gap>0;gap = gap/2){
		for(i=gap;i<n;i++){
			cur = a[i];
			for(j=i;j>=gap&&a[j-gap]>cur;j -= gap){
				a[j] = a[j-gap];
			}
			a[j] = cur;	//这里不能用a[i]，因为a[i]可能已经变了 
		}
	} 
}

int main(){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		} 
		//shell排序
		ShellSort(buf,n);
		//打印
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		} 
		printf("\n");
	}
	return 0;
} 

