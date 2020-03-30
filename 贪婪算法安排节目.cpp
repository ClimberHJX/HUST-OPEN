#include<stdio.h>
#include<algorithm>
using namespace std;
struct program{
	int Tis;
	int Tie;
	bool operator <(const program &A)const{
		return Tie<A.Tie; 
	}
}buf[100];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].Tis,&buf[i].Tie);	
		} 
		sort(buf,buf+n);
		int count = 1;
		int timeflag = buf[0].Tie;
		for(int i=1;i<n;i++){
			if(buf[i].Tis<timeflag) continue;
			else{
				count++;
				timeflag = buf[i].Tie;
			}
		}
		printf("%d\n",count);
	}
	return 0;
} 
