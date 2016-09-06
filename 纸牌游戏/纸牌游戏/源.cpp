/*
纸牌游戏：拖拉机
实现：两个队列（双方手牌）一个栈（桌上的牌）
出牌->出队
赢牌->进队
赢牌->打出的牌与桌子上的相同 枚举或者标记（桶排序实现）
*/
#include<stdio.h>
#include<Windows.h>
struct queue{
	int data[1000];
	int head;
	int tail;
};
struct stack{
	int data[10];
	int top;
};
int main(void){
	struct queue q1, q2;//声明两个队列
	struct stack s;//声明一个栈
	int book[10];//声明一个数组用于标记
	int i, t;
	q1.head = 1; q1.tail = 1;//初始化
	q2.head = 1; q2.tail = 1;
	s.top = 0;
	for (i = 1; i <= 9; i++){//初始化标记数组
		book[i] = 0;
	}
	for (i = 1; i <= 6; i++){//小哼手上的牌 ----入队
		scanf_s("%d", &q1.data[q1.tail]);
		q1.tail++;//指向最后一张牌的后一个位置
	}
	for (i = 1; i <= 6; i++){//小哈手中的牌 ----入队
		scanf_s("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	while (q1.head < q1.tail&&q2.head < q2.tail){//当队列不为空时执行循环
		t = q1.data[q1.head];//小哼先出第一张牌
		//判断小哼此轮有没有赢牌
		if (book[t] == 0){//桌面上没有牌面为t的牌
			q1.head++;//出队
			s.top++;//top=1
			s.data[s.top] = t;//入栈
			book[t] = 1;//标记桌子上的牌
		}
		else
		{
			q1.head++;//出队
			q1.data[q1.tail] = t;//入队
			q1.tail++;
			while (s.data[s.top]!=t)//把桌子上的牌依次放在牌的末尾
			{
				book[s.data[s.top]] = 0;//取消标记
				q1.data[q1.tail] = s.data[s.top];//依次入队
				q1.tail++;
				s.top--;
			}
			//收回栈中的标记为t的牌
			book[s.data[s.top]] = 0;//取消标记
			q1.data[q1.tail] = s.data[s.top];//入队
			q1.tail++;
			s.top--;
		}
		if (q1.head == q1.tail) break;// 小哼手中的牌如果打完，游戏结束
		t = q2.data[q2.head];//小哈出牌
		if (book[t] == 0){//桌面上没有牌面为t的牌
			q2.head++;//出队
			s.top++;//top=1
			s.data[s.top] = t;//入栈
			book[t] = 1;//标记桌子上的牌
		}
		else
		{
			q2.head++;//出队
			q2.data[q2.tail] = t;//入队
			q2.tail++;
			while (s.data[s.top] != t)//把桌子上的牌依次放在牌的末尾
			{
				book[s.data[s.top]] = 0;//取消标记
				q2.data[q2.tail] = s.data[s.top];//依次入队
				q2.tail++;
				s.top--;
			}
			//收回栈中的标记为t的牌
			book[s.data[s.top]] = 0;//取消标记
			q2.data[q2.tail] = s.data[s.top];//入队
			q2.tail++;
			s.top--;
		}
	}
	if (q2.head == q2.tail){
		printf("小哼赢了\n");
		printf("小哼当前手中的牌是");
		for (i = q1.head; i <= q1.tail - 1; i++)
			printf("%d", q1.data[i]);
		if (s.top > 0){
			printf("\n桌子上的牌是");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);
		}
		else
			printf("\n桌子上已经没牌了");
		
	}
	else
	{
		printf("小哈赢了\n");
		printf("小哈当前手中的牌是");
		for (i = q2.head; i <= q2.tail - 1; i++)
			printf("%d", q2.data[i]);
		if (s.top > 0){
			printf("\n桌子上的牌是");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);
		}
		else
			printf("\n桌子上已经没牌了");
	}
	system("pause");
	return 0;
}