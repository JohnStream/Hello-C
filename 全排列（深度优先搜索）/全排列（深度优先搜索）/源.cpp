/*
�������������
�ؼ����ڽ����������ô��������һ����ô���ڵ�����ô��һ��

*/
#include<stdio.h>
#include<Windows.h>
int a[10], book[10], n;//C���Ե�ȫ�ֱ�����û�и�ֵ����ǰĬ��Ϊ0�������ʼ��Ϊ0  
void dfs(int step){//step---�ڼ�������֮ǰ      
	int i;  
	if (step == n + 1){   //������������� 
		for (i = 1; i <= n; i++)
			printf("%d", a[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++){
		// ����ÿһ�����
		if (book[i] == 0){       
			a[step] = i;
			book[i] = 1;		
			dfs(step + 1);//�ݹ�		 n*n��ѭ��
			book[i] = 0;//���ղŵĳ��Ե��˿����ջأ����ܽ�����һ�γ���
		}
		
	}
	return;
}
int main(){
	scanf_s("%d", &n);
	dfs(1);
	system("pause");
}