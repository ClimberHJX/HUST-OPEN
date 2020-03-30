#include<stdio.h>
int a,b;
char num[100]; 
int main(){
	while(scanf("%d%s%d",&a,num,&b)!=EOF){
		long long sum =0;
		//计算10进制的a 
		for(int i=0;num[i]!='\0';i++){
			if(num[i]<='F'&&num[i]>='A'){
				sum = (num[i]-'A'+10+sum)*a;
			}
			else if(num[i]<='f'&&num[i]>='a'){
				sum = (num[i]-'a'+10+sum)*a;
			}else{
				sum = (num[i]-'0'+sum)*a;
			}
		}
		sum /= a;
		//转换为b进制
		char output[100];
		int j;
		for(j=0;sum!=0;j++){
			int chara = sum%b;
			if(chara>9){
				output[j] = 'A'+ chara-10;
			}else
				output[j] = chara+'0';
			sum/=b;
		} 
		for(int i=j-1;i>=0;i--){
			printf("%c",output[i]);
		}
		printf("\n");
	}
	return 0;
}

//计算数组中字符数可以加
//string.h
//strlen() 
