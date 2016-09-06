/*
算法复杂度为O（M+N）
需要先明确数据内容
*/
#include<stdio.h>
int main(){
	int a[11], i, j, t;//多大的数据规模就要申请多大的数组
	for (i = 0; i <= 10; i++){
		a[i] = 0;//init(a)
	}
	for (i = 1; i <= 5; i++){//学生成绩用下标来代替 
		scanf_s("%d", &t);
		a[t]++;
	}
	for (i = 0; i <= 10; i++)//遍历数组，出现几次打印几次
		for (j = 1; j <= a[i]; j++)
			printf("%d", i);
	getchar();
	return 0;
}