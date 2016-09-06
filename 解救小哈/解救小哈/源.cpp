#include<stdio.h>
#include<Windows.h>
int n, m, p, q, min = 9999999;
int a[51][51];//储存地图
int book[51][51];//标记是否已经存在路径中
void dfs(int x, int y, int step){
	int next[4][2] = { { 0, 1 }//向右 ->当前点的横坐标+1
						, { 1, 0 }//向下
						, { 0, -1 }//向左
						, { -1, 0 } };//向上
	int tx, ty, k;//判断小哈位置
	if (x == p&&y == q){
		//更新最小值
		if (step < min)
			min = step;
		return;
	}
		for (k = 0; k <= 3; k++){
			tx = x + next[k][0];
			ty = y + next[k][1];
			if (tx<1 || tx>n || ty<1 || ty>m)//判断越界
				continue;//跳到下一层循环
				if (a[tx][ty] == 0 && book[tx][ty] == 0){//判断该点是否已经存在路径中
					book[tx][ty] = 1;
					dfs(tx, ty, step+1);//尝试下一个点
					book[tx][ty] = 0;
				}			
		}	
	return;
}
int main(){
	int i, j, startx, starty;
	scanf_s("%d %d", &n, &m);
	for (i = 1; i <= n; i++)//读入迷宫
		for (j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	scanf_s("%d %d %d %d", &startx, &starty, &p, &q);
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("%d", min);			
	system("pause");
	return 0;
	
}