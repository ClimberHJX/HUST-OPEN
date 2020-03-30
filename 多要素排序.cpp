#include<stdio.h>
#include<algorithm>
#include<string.h>	//strcmp
using namespace std;
struct E{
	char name[101];
	int age;
	int score;
}buf[1000];
int n;
//定义排序规则 
bool cmp(E a,E b){
	if(a.score!=b.score)	return a.score<b.score;
	int tmp = strcmp(a.name,b.name);
	if(tmp!=0) return tmp<0;
	else return a.age<b.age;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);		//这里的name是char数组，所以不加取址符 
		}
		sort(buf,buf+n,cmp);	//计算机无法对两个结构体进行比较，所以自定义比较规则 
		for(int i=0;i<n;i++){
			printf("%s %d %d",buf[i].name,buf[i].age,buf[i].score);
			printf("\n"); 
		} 
	}
	return 0;
}
