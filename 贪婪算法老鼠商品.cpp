#include<stdio.h>
#include<algorithm>
using namespace std;
struct goods{
	double weight;
	double value;
	double cp;
	bool operator < (const goods &A)const{
		return cp< A.cp;
	}
}buf[1000];
int main(){
	int N;
	double M;
	while(scanf("%lf%d",&M,&N)!=EOF){
		if(M==-1&&N==-1){
			break;
		}
		for(int i=0;i<N;i++){
			scanf("%lf%lf",&buf[i].weight,&buf[i].value);
			buf[i].cp = buf[i].weight/buf[i].value;
		}
		sort(buf,buf+N);
		double sum = 0;
		for(int i=N-1;i>=0;i--){
			if(buf[i].value<=M){
				sum+=buf[i].weight;
				M-=buf[i].value; 
			}else if(M>0&&buf[i].value>=M){
				sum+=buf[i].cp*M;
				M=0;
				printf("%.3lf\n",sum);
				break;
			} 
		}
		if(M>0){
			printf("%.3lf\n",sum);
		}
	}
	return 0;
} 
