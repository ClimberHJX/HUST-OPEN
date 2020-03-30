#include<stdio.h>
void merge(int a[],int start,int end){
	int temp[end-start+1];
	int temflag = 0,middle=(start+end)/2;
	int i = start,j = middle+1;
	while(i<=middle&&j<=end){
		if(a[i]<=a[j]){
			temp[temflag] = a[i];
			i++; 
		}else{
			temp[temflag] = a[j];
			j++;	
		}
		temflag++;
	}
	while(temflag!=end-start+1){
		if(j<=end){
			temp[temflag] = a[j];
			j++;
		}
		if(i<=middle){
			temp[temflag] = a[i];
			i++;
		}
		temflag++;
	}
	
	for(int k=0;k<=end-start;k++){
		a[start + k] = temp[k];
	} 
}

void mergeSort(int a[],int start,int end){
		if(start >= end)
			return;
		int middle = (start + end)/2;
		mergeSort(a,start,middle);
		mergeSort(a,middle+1,end);
		merge(a,start,end);
}

int main(){
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		} 
		//¹é²¢ÅÅĞò
		mergeSort(buf,0,n-1);
		//´òÓ¡
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		} 
		printf("\n");
	}
	return 0;
} 
