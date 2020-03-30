#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;	//建立小顶堆
//默认是大顶堆 
//https://www.cnblogs.com/huashanqingzhu/p/11040390.html
//Error Attention:[Error] '>>' should be '> >' within a nested template argument list
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(Q.empty()==false) Q.pop();
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			Q.push(x); 
		}
		int ans = 0;
		while(Q.size()>1){
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a + b;
			Q.push(a+b);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
