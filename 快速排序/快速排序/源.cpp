/*
快速排序
算法复杂度为O（n²），平均复杂度为O（NlogN）;
快速排序是基于一种叫做二分查找的思想；
*/
#include<stdio.h>
int a[101], n;//定义全局变量
void quicksort(int left, int right){//快速排序
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left];//temp里存放基准数
	i = left;
	j = right;
	while (i!=j)//右边寻找小于基准数的数，左边寻找大于基准数的数 
	{
		while (a[j] >= temp&&i < j)//如果数大于基准数 就右移
			j--;
		while (a[i] <= temp&&i < j)
			i++;
	}
	if (i < j){//交换两个数的位置
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);//二分思想
	quicksort(i + 1, right);//二分思想
	return;
}
int main(){
	int i, j;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++){
		scanf_s("%d", &a[i]);
	}
	quicksort(1, n);
	for ( i = 1; i <=n; i++)
		printf("%d", a[i]);
	getchar(); getchar();
	return 0;
}