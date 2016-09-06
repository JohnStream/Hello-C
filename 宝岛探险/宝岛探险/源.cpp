/*广度优先
该代码执行结果与书本不符*/
#include<stdio.h>
struct note{
	int x;
	int y;
};
int main(){
	struct note que[2501];
	int head, tail;int a[51][51];
	
	int book[51][51] = { 0 };
	int i, j, k, sum, max = 0, n, m, startx, starty, tx, ty;
	//定义方向
	int next[4][2] = { { 0, 1 },
						{1, 0},
						{ 0, -1 },
						{ -1, 0 } };
	//读入N行M列已经小哼的降落的目标
	scanf_s("%d %d %d %d",&n,&m,&startx,&starty);
	//读入地图
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf_s("%d", &a[i][j]);
	//队列初始化
	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	//当队列不为空的时候循环
	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if (tx<1 || tx>n || ty<1 || ty>m){
				continue;
				//	判断是否是陆地或者曾经走过
				if (a[tx][ty] > 0 && book[tx][ty] == 0)
					sum++;
				//每个点只入队一次，所以需要标记这个点已经走过
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;
	}
	printf_s("%d\n", sum);
	getchar(); getchar();
	return 0;
}