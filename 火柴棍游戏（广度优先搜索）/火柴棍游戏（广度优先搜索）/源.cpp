#include<stdio.h>
#include<Windows.h>
int a[10], book[10], n=0;
void dfs(int step){
	int i;
	if (step == 10){//条件成立则输出 
		if (a[1] * 100 + a[2] * 10 + a[3] +a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9]){
			n++;
			printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
		}
		return;
	}
	for (i = 1; i <= 9; i++){//遍历每一种情况
		if (book[i] == 0){
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}
int main(){
	dfs(1);
	printf("共用%d种方法", n / 2);
	system("pause");
}