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
//����������� 
bool cmp(E a,E b){
	if(a.score!=b.score)	return a.score<b.score;
	int tmp = strcmp(a.name,b.name);
	if(tmp!=0) return tmp<0;
	else return a.age<b.age;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);		//�����name��char���飬���Բ���ȡַ�� 
		}
		sort(buf,buf+n,cmp);	//������޷��������ṹ����бȽϣ������Զ���ȽϹ��� 
		for(int i=0;i<n;i++){
			printf("%s %d %d",buf[i].name,buf[i].age,buf[i].score);
			printf("\n"); 
		} 
	}
	return 0;
}
