/*�����������*/
/*�ֳ���ɫ��*/
#include<stdio.h>
int a[51][51];
int book[51][51], n, m, sun;
void dfs(int x, int y){
	//����һ����������
	int next[4][2] = { { 0, 1 },
						{ 1, 0 },
						{ 0, -1 },
						{ -1, 0 } };
	int k, tx, ty;
	for (k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
	}
}
