#include<stdio.h>	//�����Ű����⡪�����Ű����� 
int main(){
	int size;
	char output[80][80];
	char a,b;
	//���������ʽ
	bool firstcase = true; 
	while(scanf("%d %c %c",&size,&a,&b)==3){
		if(firstcase==true){
			firstcase = false;
		}else{
			printf("\n");
		}
		
		for(int i=0,j=0;i<size;i+=2,j++){//���ﵽ��һȦȦ��ֵ 
			int x = (size-1)/2,y=x;
			x -= j;y -= j;
			char c = j%2 == 0? a:b;
			for(int k=0;k<=i;k++){ 
				output[x][y+k] = c;
				output[x+k][y+i] = c;
				output[x+i-k][y] = c;
				output[x+i][y+i-k] = c;
			}
		}
		if(size!=1){//�Ľ� 
			output[0][0] = ' ';
			output[size-1][size-1] = ' ';
			output[size-1][0] = ' ';
			output[0][size-1] = ' ';
		}
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				printf("%c",output[i][j]);
			}
			printf("\n");
		}
		
	}
	return 0;
} 
