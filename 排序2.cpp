//C++的快速排序api
#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	int n;
	int buf[1000];
	while(scanf("%d",&n)!=EOF){
		for(int i = 0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		//排序函数 
		sort(buf,buf+n);
		//参数为起始地址，结束地址	
		//sort的另一种重载方式
		sort(buf,buf+n,greater<int>());	 //倒序			另：greater的使用在 functional头文件里面 
		//正序 sort(buf,buf+n,less<int>());	 或者默认 
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
} 
