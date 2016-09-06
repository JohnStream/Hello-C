#include<stdio.h>
/*
冒泡排序
算法复杂度为O（n²）
*/
struct student
{
	char name[21];
	int sorce;
};
int main(){
	struct student a[100],t;
	int i, j,n;//i控制外层循环，j控制内层循环
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)//循环输入值
		scanf_s("%s %d",a[i].name,&a[i].sorce);//字符本身存放的是地址，不要用&符号
	for (i = 1; i <= n; i++){
		printf("%s %d", a[i].name, a[i].sorce);
	}
	for (i = 1; i <=n-1; i++)
		for (j = 1; j <=n-i ; j++){
		if (a[j].sorce < a[j + 1].sorce){//比较相邻两个数的大小。这里是从大到小排序
			t = a[j];
			a[j] = a[j + 1];
			a[j + 1] = t;
		}
		}
	for (i = 1; i <= n; i++){
		printf("%s %d", a[i].name,a[i].sorce);
	}
	getchar();
	getchar();
}