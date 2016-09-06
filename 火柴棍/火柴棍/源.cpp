/*
20根火柴 其中数字1字需要2根火柴 可以组成10个数字 所以A+B=C任意一个不会大于
*/
#include<stdio.h>
#include<stdlib.h>
int fun(int x){
	int num = 0;
	int f[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	while (x / 10 != 0){
		num += f[x % 10];
		x = x / 10;
	}
	num += f[x];
	return num;
}
int main(){
	int a, b, c, m, sum=0;//sum 用来计数，必须初始化
	scanf_s("%d", &m);
	for (a = 0; a <= 1111; a++){
		for (b = 0; b < 1111; b++){
			c = a + b;
			if (fun(a)+fun(b)+fun(c)==m-4){
				printf("%d+%d=%d\n", a, b, c);
				sum++;
			}
		}
	}
	printf("一共可以拼出%d个不同的等式", sum);
	system("pause");
}
