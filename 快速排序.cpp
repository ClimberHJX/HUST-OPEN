#include<stdio.h>

int partition(int a[],int start,int end){
	int pivot = a[end],i = start-1,j,tmp;
	for(j=start;j<=end-1;j++){
		if(a[j]<pivot){
			i+=1;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp; 
		}
	}	
	a[end] = a[i+1];
	a[i+1] = pivot;
	return i+1;
}

void quickSort(int a[],int start,int end){
	if(start>=end)
		return;
	int q = partition(a,start,end);
	quickSort(a,start,q-1);
	quickSort(a,q+1,end);
} 

int main(){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		} 
		//¹é²¢ÅÅÐò
		quickSort(buf,0,n-1);
		//´òÓ¡
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		} 
		printf("\n");
	}
	return 0;	
} 
