/*炸弹人游戏
#----墙
.----空地
G----敌人
*/
#include<stdio.h>
#include<windows.h>
int main(){
	char a[20][21];//地图最大值
	int i, j, sum, map = 0, p, q, x, y, n, m;
	scanf_s("%d %d", &n, &m);//n---行 m---列
	for (i = 0; i <= n - 1; i++){//这种方法无法连续读入字符串
		scanf_s("%s", a[i]);
	}
	//循环遍历地图每一个点
	for (i = 0; i <= n - 1; i++){
		for (j = 0; j <= m - 1; j++){
			if (a[i][j] == '.'){//空地才能安放子弹
				sum = 0;//sum---消灭敌人的数量，初始化
				//将当前坐标i，j赋值给x,y,方便上下左右四个方向的变量分别统计
				x = i; y = j;
				while (a[x][y] != '#'){//判断是不是墙
					if (a[x][y] == 'G')
						sum++;//统计当前行
					x--;//向上统计
				}
				//向下统计
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					x++;
				}
				//向右统计
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					y--;
				}
				//向左统计
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					y++;
				}
				if (sum > map){//如果当期消灭敌人总数大于map,则更新map
					map = sum;
					//p,q记录当期坐标
					p = i;
					q = j;
				}
			}
		}
	}
	printf("将炸弹放置在(%d,%d),最多可以消灭%d个敌人\n", p, q, map);
	system("pause");
}