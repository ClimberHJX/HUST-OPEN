#include<stdio.h>
int n;
int buf[100];

int main(){
	while(scanf("%d",&n)!=EOF) {//ʵ�ֶ������� 
		int i,j;
		for(i=0;i<n;i++){
			scanf("%d",&buf[i]);
		} 
		//����ʽ��������
		for(i=1;i<n;i++){
			int key = buf[i];
			j = i-1;
			while(j>-1&&buf[j]>key){
				buf[j+1] = buf[j];
				j=j-1;
			}
			buf[j+1] = key;
		}
	
		//ð������
		for(i=0;i<n-2;i++){
			for(j=0;j<n-1-i;j++){
				if(buf[j]>buf[j+1]){
					int temp = buf[j];
					buf[j] = buf[j+1];
					buf[j+1] = temp;
				}
			}
		} 
		//���
		for(i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}

