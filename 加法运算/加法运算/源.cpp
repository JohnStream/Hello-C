#include<stdio.h>
#include<Windows.h>
int dg(int s){//�ݹ�
	if (s == 1)
		return 1;	
	else	
	return   s+	dg(s - 1);
}
int main(){
	int sum =0,n= 0;
	for (int i = 1; i <=100; i++){//ѭ��
		sum = sum + i;
	}
	printf("%d\n", sum);
	n=dg(100);
	printf("%d\n", n);
	system("pause");
	return 0;
}