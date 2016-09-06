#include<stdio.h>
#include<Windows.h>
int n, m, p, q, min = 9999999;
int a[51][51];//�����ͼ
int book[51][51];//����Ƿ��Ѿ�����·����
void dfs(int x, int y, int step){
	int next[4][2] = { { 0, 1 }//���� ->��ǰ��ĺ�����+1
						, { 1, 0 }//����
						, { 0, -1 }//����
						, { -1, 0 } };//����
	int tx, ty, k;//�ж�С��λ��
	if (x == p&&y == q){
		//������Сֵ
		if (step < min)
			min = step;
		return;
	}
		for (k = 0; k <= 3; k++){
			tx = x + next[k][0];
			ty = y + next[k][1];
			if (tx<1 || tx>n || ty<1 || ty>m)//�ж�Խ��
				continue;//������һ��ѭ��
				if (a[tx][ty] == 0 && book[tx][ty] == 0){//�жϸõ��Ƿ��Ѿ�����·����
					book[tx][ty] = 1;
					dfs(tx, ty, step+1);//������һ����
					book[tx][ty] = 0;
				}			
		}	
	return;
}
int main(){
	int i, j, startx, starty;
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)//�����Թ�
		for (j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	scanf_s("%d %d %d %d", &startx, &starty, &p, &q);
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("%d", min);			
	system("pause");
	return 0;
	
}