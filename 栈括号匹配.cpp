#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;
int main(){
	char input[101];
	char output[101];
	while(scanf("%s",input)!=EOF){
		int i;
		for(i=0;input[i]!='\0';i++){
			if(input[i] == '('){
				S.push(i);
				output[i] = ' ';
			}else if(input[i]==')'){
				if(S.empty()==true){
					output[i] = '?';
				}else{
					S.pop();
					output[i] = ' ';
				}
			}else{
				output[i] = ' ';
			}
		}
		output[i] = '\0';
		while(S.empty()==false){
			output[S.top()] = '$';
			S.pop();
		}
		puts(input);
		puts(output);
	}
}
