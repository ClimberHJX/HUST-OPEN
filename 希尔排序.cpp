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
			a[j] = cur;	//���ﲻ����a[i]����Ϊa[i]�����Ѿ����� 
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
		//shell����
		ShellSort(buf,n);
		//��ӡ
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		} 
		printf("\n");
	}
	return 0;
} 

