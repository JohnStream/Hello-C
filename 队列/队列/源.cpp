#include<stdio.h>
#include<Windows.h>
/*
int main(){
	int q[102] = { 0, 6, 3, 1, 7, 5, 8, 9, 2, 4 }, head, tail;
	head = 1;
	tail = 10;//tail指向队尾的后一个位置
	while (head < tail){//当队列不为空的时候执行循环
		printf("%d", q[head]);
		head++;
		q[tail] = q[head];
		tail++;
		head++;
	}
	system("pause");
}
*/
struct queue{
	int data[100];
	int head;
	int tail;
};
int main(){
	struct queue q;
	int i;
	q.head = 1;
	q.tail = 1;
	for ( i = 1; i <=9; i++)
	{
		scanf_s("%d", &q.data[q.tail]);
		q.tail++;
	}
	while (q.head<q.tail)
	{
		printf("%d", q.data[q.head]);
		q.head++;
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		q.head++;
	}
	system("pause");
}