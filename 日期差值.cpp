#include<stdio.h>
#define ISLEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1:0	//定义宏判断是否为闰年 
int dayOfMonth[13][2] = {
0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
} ;//预存每个月的天数，对2月做特殊处理
struct Date{
	int Day;
	int Month;
	int Year;
	void nextDay(){
		Day++;
		if(Day>dayOfMonth[Month][ISLEAP(Year)]){//如果日数超过了当月最大 
			Day = 1;
			Month++;
			if(Month>12){
				Month = 1;
				Year++;
			} 
		}
	}
}; 

int buf[5001][13][32] ;
int Abs(int x){
	return x<0?-x:x;
}
int main(){
	Date tmp;
	int cnt = 0;//天数计数
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;	//初始化日期类对象为0年1月1日
	while(tmp.Year!=5001){//日期不超过5000年 
		buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.nextDay();
		cnt++;
	} //通过循环的方式吧0年1月1日到5001年的每个日期与标准值的差存储下来
	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	} 
	return 0;
}
//在一开始的疑惑，为什么数组的大小是这样的：考虑访问数组是下标差1的情况 
