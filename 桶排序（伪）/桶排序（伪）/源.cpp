/*
�㷨���Ӷ�ΪO��M+N��
��Ҫ����ȷ��������
*/
#include<stdio.h>
int main(){
	int a[11], i, j, t;//�������ݹ�ģ��Ҫ�����������
	for (i = 0; i <= 10; i++){
		a[i] = 0;//init(a)
	}
	for (i = 1; i <= 5; i++){//ѧ���ɼ����±������� 
		scanf_s("%d", &t);
		a[t]++;
	}
	for (i = 0; i <= 10; i++)//�������飬���ּ��δ�ӡ����
		for (j = 1; j <= a[i]; j++)
			printf("%d", i);
	getchar();
	return 0;
}