#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int mat[][5] = {//�������Ⱦ������mat[i][j]=1,���ʾi�����ȼ�����j��+1-2*3/4��//��Ϊ����ڱ��ʽ��β�ķ������ȼ�Ϊ0 
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,1,1,0,0,
1,1,1,0,0, 
};
stack<int> op;//��ŷ��ű�� 
stack<double> num;//����ջ 
char str[201];

void getOP(bool &reto,int &retn,int &i){//��ȡ���ʽ����һ��Ԫ�أ�Ϊ���Ǵ��ַ��������ַ��ź����� 
	//�� 
	if(i == 0 && op.empty() == true){//������һ���ַ���������ջΪ�գ������Ϊ���Ϊ0���ַ� 
		reto = true;
		retn = 0;
		return;
	}
	//β 
	if(str[i] == '\0'){
		reto = true;
		retn = 0;
		return;
	} 
	//����
	if(str[i]>='0'&&str[i]<='9') {
		reto = false;
	}else{
		//���� 
		reto = true;
		if(str[i] == '+'){
			retn = 1;
		}else if(str[i] == '-'){
			retn = 2;
		}
		else if(str[i] == '*'){
			retn = 3;
		}else
			retn = 4;
		i+=2;
		return;
	}
	retn = 0;
	//��������
	for(;str[i]!=' '&&str[i]!='\0';i++){
		retn*=10;
		retn += str[i] - '0';
	} 
	if(str[i]==' '){
		i++;
	}
	return;
}

int main(){
	while(gets(str)){
		if(str[0] == '0' && str[1] == '\0') break;
		bool retop; int retnum;
		int idx = 0;
		//��Ϊ�ж������ݣ����Բ�Ҫ�������ջ 
		while(!op.empty()) op.pop();
		while(!num.empty()) op.pop();
		while(true){
			getOP(retop,retnum,idx);
			if(retop == false){//���� 
				num.push((double)retnum);
			}else{
				double tmp;
				if(op.empty() == true || mat[retnum][op.top()] == 1){
					op.push(retnum);
				}else{
					while(mat[retnum][op.top()] == 0){//����ʹ��whileѭ���ǿ��ǵ����� ��ջ��ʣ��#-+#����� 
						int ret = op.top();
						op.pop();
						double b = num.top();	//����˵��һ��pop()�ķ���ֵ��void 
						num.pop();
						double a = num.top();
						num.pop();
						if(ret == 1){
							tmp = a+b;
						}else if(ret == 2){
							tmp = a-b;
						}else if(ret == 3){
							tmp = a*b; 
						}else{
							tmp = a/b;
						}
						num.push(tmp);
					}
					op.push(retnum);
				}
			} 
			if(op.size() == 2 && op.top() == 0)
				break;
		} 
		printf("%.2lf\n",num.top());
	}
	return 0;
} 
