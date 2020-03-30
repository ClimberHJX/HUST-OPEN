#include<stdio.h>
#include<algorithm>
#include<string.h>	//strcmp
using namespace std;
struct E{
	char name[101];
	int age;
	int score;
	bool operator < (const E &b) const{	//重载<操作符，对两个node进行比较操作 
		if(score!=b.score)	return score<b.score;
		int tmp = strcmp(name,b.name);
		if(tmp!=0) return tmp<0;
		else return age<b.age;
	} 
}buf[1000];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);		
		}
		sort(buf,buf+n);
		for(int i=0;i<n;i++){
			printf("%s %d %d",buf[i].name,buf[i].age,buf[i].score);
			printf("\n"); 
		} 
	}
	return 0;
}
//重载运算符的概念	https://www.cnblogs.com/ECJTUACM-873284962/p/6771262.html 
