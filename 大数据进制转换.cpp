#include<stdio.h>
#include<string.h>
#define maxDigits 100
struct bigInteger{
	int digit[maxDigits];
	int size;
	void init(){//初始化 
		for(int i=0;i<maxDigits;i++) digit[i] = 0;
		size = 0;
	}
	void set(int x){//用普通整数来初始化高精度 
		init();
		do{
			digit[size++] = x%10000;
			x /= 10000; 
		}while(x!=0);
	}
	void output(){
		for(int i = size-1;i>=0;i--){
			if(i!=size-1) printf("%04d",digit[i]);
			else printf("%d",digit[i]);
		}
		printf("\n");
	}
	bigInteger operator * (int x) const{//高精度整数与普通整数的乘积 
		bigInteger ret;
		ret.init();
		int carry = 0;//进位 
		for(int i=0;i<size;i++){
			int tmp = x*digit[i] + carry;
			carry = tmp / 10000;
			tmp = tmp%10000;
			ret.digit[ret.size++] = tmp;
		} 
		if(carry!=0){
			ret.digit[ret.size++] = carry;
		}
		return ret;
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
	bigInteger operator / (int x) const{//高精度整数与普通整数的除 
		bigInteger ret;
		ret.init();
		int remainder = 0;//余位 
		for(int i=size-1;i>=0;i--){
			int t = (remainder*10000+digit[i])/x;
			int r = (remainder*10000+digit[i])%x; 
			ret.digit[i] = t;
			remainder = r;
		} 
		ret.size = 0;
		for(int i=0;i<maxDigits;i++){//确定最高f非0位 
			if(digit[i]!=0) ret.size=i;
		}
		ret.size++;
		return ret;
	}
	int operator % (int x) const{
		int remainder = 0;
		for(int i=size-1;i>=0;i--){
			int r = (remainder*10000+digit[i])%x; 
			remainder = r;
		} 
		return remainder;
	}
} a,b,c;

char str[10000];
char ans[10000];
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		scanf("%s",str);
		int L = strlen(str);
		a.set(0);//用来保存转换成10进制的M进制数
		b.set(1);//在m进制向10进制转换的过程中，依次代表每一位的权重
		for(int i=L-1;i>=0;i--){
			int t;
			if(str[i] >= '0'&& str[i]<'9'){
				t = str[i] - '0';
			}else{
				t = str[i] - 'A' +10;
			}
			a = a + b * t;				//获取某位的 10进制值，对应到大数据为：* + 
			b = b * m;					//获取下一位的权重 ：* 
		} 
		//向N位进制转换需要：/ %
		int size = 0;
		do{
			int t = a%n;
			if(t>=10){
				ans[size++] = t-10+'a';
			}else{
				ans[size++] = t + '0';
			}
			a = a/n;
		} while(a.digit[0]!=0||a.size!=1);	//该条件等价于a==0 
		
		//输出
		for(int i=size-1;i>=0;i--){
			printf("%c",ans[i]);
		} 
		printf("\n");
	}
	return 0;
}
