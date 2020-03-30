#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int mat[][5] = {//符号优先矩阵，如果mat[i][j]=1,则表示i的优先级高于j，+1-2*3/4。//人为添加在表达式首尾的符号优先级为0 
1,0,0,0,0,
1,0,0,0,0,
1,0,0,0,0,
1,1,1,0,0,
1,1,1,0,0, 
};
stack<int> op;//存放符号编号 
stack<double> num;//数字栈 
char str[201];

void getOP(bool &reto,int &retn,int &i){//获取表达式的下一个元素，为的是从字符串中区分符号和数字 
	//首 
	if(i == 0 && op.empty() == true){//遍历第一个字符，且运算栈为空，添加人为编号为0的字符 
		reto = true;
		retn = 0;
		return;
	}
	//尾 
	if(str[i] == '\0'){
		reto = true;
		retn = 0;
		return;
	} 
	//数字
	if(str[i]>='0'&&str[i]<='9') {
		reto = false;
	}else{
		//符号 
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
	//计算数字
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
		//因为有多组数据，所以不要忘记清空栈 
		while(!op.empty()) op.pop();
		while(!num.empty()) op.pop();
		while(true){
			getOP(retop,retnum,idx);
			if(retop == false){//数字 
				num.push((double)retnum);
			}else{
				double tmp;
				if(op.empty() == true || mat[retnum][op.top()] == 1){
					op.push(retnum);
				}else{
					while(mat[retnum][op.top()] == 0){//这里使用while循环是考虑到：如 ：栈中剩下#-+#的情况 
						int ret = op.top();
						op.pop();
						double b = num.top();	//这里说明一下pop()的返回值是void 
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
