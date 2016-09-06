#include "stdio.h"
#include<Windows.h>
void abc(int n)
{
	int i;
	for (i = 1; i <= 2; i++)
	{
		if (n > 0)
		{
			abc(n - 1);
			printf("%d\n", n);
		}
	}
}

int main()
{
	abc(2);
	system("pause");
	return 0;
}
/*
1输入2  abc执行
2进入循环 i=1
3第一层递归 执行 abc(n-1)     //n此时为2
4进入第二层递归的循环  n为1 ，再次执行 abc(n-1)  //此时n为1
5 进入第三层递归的循环  n为0  n不满足if条件 空循环2次 函数结束
6 继续执行 第4步 打印 n   n=1
7进入 第4步中的第二次循环   执行第5步空循环  再执行第6步   此时输出为 “1\n1\n”了
8第二层递归结束，第一层递归 继续执行  打印 2  此时输出结果 “1\n1\n2\n”
9 开始第一层递归的 第二次循环  重复 第3到第8步  一次
*/