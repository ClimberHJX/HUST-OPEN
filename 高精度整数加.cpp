#include<stdio.h>
#include<string.h>
struct bigInteger{
	int digit[1000];
	int size;	//下一个可以使用的数组单元 
	//保存整数123456789
	//digit[0] = 6789;digit[1] = 2345;dight[2] = 1;size = 3;
	void init(){
		for(int i=0;i<1000;i++)
			digit[i] = 0;
		size = 0;
	}
	void set(char str[]){
		init();
		int L = strlen(str);
		for(int i = L-1,j = 0,t = 0,c = 1;i>=0;i--){
			t += (str[i]-'0') * c;
			j++;
			c *=  10;
			if(j==4||i==0){
				digit[size++] = t;
				j = 0;
				c = 1;
				t = 0;
			}
		}
	}
	void output(){
		for(int i = size-1;i>=0;i--){
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		}
		printf("\n");
	}
	bigInteger operator + (const bigInteger &A) const{
		bigInteger ret;
		ret.init();
		int carry = 0;//进位 
		for(int i=0;i<A.size||i<size;i++){
			int tmp = A.digit[i] + digit[i] + carry;
			carry = tmp / 10000;
			tmp = tmp%10000;
			ret.digit[ret.size++] = tmp;
		} 
		if(carry!=0){
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}
}a,b,c;

int main(){
	char str1[1002],str2[1002];
	while(scanf("%s%s",str1,str2)!=EOF){
		a.set(str1);
		b.set(str2);
		c = a+b;
		c.output();
	}
	return 0;
}





