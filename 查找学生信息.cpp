#include<stdio.h>
#include<algorithm>
#include<string.h> //¶þ·Ö²éÕÒ 
using namespace std;
struct Student{
	char no[100];
	char name[100];
	int age;
	char sex[5];
	bool operator < (const Student &A) const{
		return strcmp(no,A.no)<0;
	};
}buf[1000]; 
int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
		}	
		sort(buf,buf+N);
		int M;
		scanf("%d",&M);
		bool find;
		while(M--!=0){
			find = false;
			char x[30];
			scanf("%s",x);
			int top = N-1,base = 0;
			while(top>=base){
				int mid = (top+base)/2;
				int tmp = strcmp(buf[mid].no,x);
				if(tmp==0){
					printf("%s %s %s %d\n",buf[mid].no,buf[mid].name,buf[mid].sex,buf[mid].age);
					find = true;
					break;
				}
				else if(tmp<0) base = mid+1;
				else top = mid-1;
			}
			if(find == false){
				printf("No Answer!\n");
			}
		}
		
	}
	return 0;
} 
