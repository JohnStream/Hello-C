/*
广度优先搜索：
关键在于解决“当下怎么做”，下一步怎么做于当下怎么做一致

*/
#include<stdio.h>
#include<Windows.h>
int a[10], book[10], n;//C语言的全局变量在没有赋值的以前默认为0，无需初始化为0  
void dfs(int step){//step---第几个盒子之前      
	int i;  
	if (step == n + 1){   //条件成立则输出 
		for (i = 1; i <= n; i++)
			printf("%d", a[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++){
		// 遍历每一种情况
		if (book[i] == 0){       
			a[step] = i;
			book[i] = 1;		
			dfs(step + 1);//递归		 n*n此循环
			book[i] = 0;//将刚才的尝试的扑克牌收回，才能进行下一次尝试
		}
		
	}
	return;
}
int main(){
	scanf_s("%d", &n);
	dfs(1);
	system("pause");
}