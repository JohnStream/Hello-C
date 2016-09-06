#include<stdio.h>
#include<Windows.h>
void hannuota(int n, char A, char B, char C){
	if (n == 1){
		printf("将编号为%d的盘子直接从%c的柱子上移动到%c柱子\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从%c的柱子上移动到%c柱子\n", n, A, C);
		hannuota(n - 1, B, A, C);
	}
}
int main(){
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n;
	scanf_s("%d", &n);
	hannuota(n, a, b, c);
	system("pause");

}