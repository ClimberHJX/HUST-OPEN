//C++�Ŀ�������api
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
		//������ 
		sort(buf,buf+n);
		//����Ϊ��ʼ��ַ��������ַ	
		//sort����һ�����ط�ʽ
		sort(buf,buf+n,greater<int>());	 //����			��greater��ʹ���� functionalͷ�ļ����� 
		//���� sort(buf,buf+n,less<int>());	 ����Ĭ�� 
		for(int i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
} 
