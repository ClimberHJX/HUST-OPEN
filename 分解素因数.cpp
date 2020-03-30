#include<stdio.h>
#include<math.h>
int prime[10000];//��¼���ֵ����� 
int mark[10001]; //�����ʵ�ʱ���Ϊ1 
int primesize = 0;
void init(){
	for(int i=0;i<=10000;i++){
		mark[i]=0;
	}
	primesize = 0;
	for(int i=2;i<=10000;i++){
		if(mark[i]==1)	//�Ѿ������ʵ� 
			continue;
		prime[primesize++] = i; 
		for(int j=i*i;j<10000;j+=i){
			mark[j] = 1;
		}
	}
} 
 
int main(){
	init();
	int n; 
	while(scanf("%d",&n)!=EOF){
		int ansPrime[30];	//��˳�򱣴�ֽ���Ķ�Ӧ��������
		int ansSize = 0;
		int ansNum[30];	// ����ֽ������������Ӧ����ָ��
		for(int i=0;i<primesize;i++){
			if(n%prime[i]==0){
				ansPrime[ansSize] = prime[i];
			}
			ansNum[ansSize] = 0;
			while(n%prime[i]==0){
				ansNum[ansSize] ++;
				n/=prime[i];
			}
			ansSize++;
			if(n==1) break;
		} 
		
		// ��������2��100000������������, n��δ�� �ֽ���1, ��ʣ�������һ��100000��������
		if(n!=1){
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;			
		}
		
		int ans = 0;
		for(int i=0;i<ansSize;i++){
			ans += ansNum[i];
		}
		printf("%d",ans);
	}
	return 0;
}
