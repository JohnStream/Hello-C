/*
ֽ����Ϸ��������
ʵ�֣��������У�˫�����ƣ�һ��ջ�����ϵ��ƣ�
����->����
Ӯ��->����
Ӯ��->��������������ϵ���ͬ ö�ٻ��߱�ǣ�Ͱ����ʵ�֣�
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
	struct queue q1, q2;//������������
	struct stack s;//����һ��ջ
	int book[10];//����һ���������ڱ��
	int i, t;
	q1.head = 1; q1.tail = 1;//��ʼ��
	q2.head = 1; q2.tail = 1;
	s.top = 0;
	for (i = 1; i <= 9; i++){//��ʼ���������
		book[i] = 0;
	}
	for (i = 1; i <= 6; i++){//С�����ϵ��� ----���
		scanf_s("%d", &q1.data[q1.tail]);
		q1.tail++;//ָ�����һ���Ƶĺ�һ��λ��
	}
	for (i = 1; i <= 6; i++){//С�����е��� ----���
		scanf_s("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	while (q1.head < q1.tail&&q2.head < q2.tail){//�����в�Ϊ��ʱִ��ѭ��
		t = q1.data[q1.head];//С���ȳ���һ����
		//�ж�С�ߴ�����û��Ӯ��
		if (book[t] == 0){//������û������Ϊt����
			q1.head++;//����
			s.top++;//top=1
			s.data[s.top] = t;//��ջ
			book[t] = 1;//��������ϵ���
		}
		else
		{
			q1.head++;//����
			q1.data[q1.tail] = t;//���
			q1.tail++;
			while (s.data[s.top]!=t)//�������ϵ������η����Ƶ�ĩβ
			{
				book[s.data[s.top]] = 0;//ȡ�����
				q1.data[q1.tail] = s.data[s.top];//�������
				q1.tail++;
				s.top--;
			}
			//�ջ�ջ�еı��Ϊt����
			book[s.data[s.top]] = 0;//ȡ�����
			q1.data[q1.tail] = s.data[s.top];//���
			q1.tail++;
			s.top--;
		}
		if (q1.head == q1.tail) break;// С�����е���������꣬��Ϸ����
		t = q2.data[q2.head];//С������
		if (book[t] == 0){//������û������Ϊt����
			q2.head++;//����
			s.top++;//top=1
			s.data[s.top] = t;//��ջ
			book[t] = 1;//��������ϵ���
		}
		else
		{
			q2.head++;//����
			q2.data[q2.tail] = t;//���
			q2.tail++;
			while (s.data[s.top] != t)//�������ϵ������η����Ƶ�ĩβ
			{
				book[s.data[s.top]] = 0;//ȡ�����
				q2.data[q2.tail] = s.data[s.top];//�������
				q2.tail++;
				s.top--;
			}
			//�ջ�ջ�еı��Ϊt����
			book[s.data[s.top]] = 0;//ȡ�����
			q2.data[q2.tail] = s.data[s.top];//���
			q2.tail++;
			s.top--;
		}
	}
	if (q2.head == q2.tail){
		printf("С��Ӯ��\n");
		printf("С�ߵ�ǰ���е�����");
		for (i = q1.head; i <= q1.tail - 1; i++)
			printf("%d", q1.data[i]);
		if (s.top > 0){
			printf("\n�����ϵ�����");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);
		}
		else
			printf("\n�������Ѿ�û����");
		
	}
	else
	{
		printf("С��Ӯ��\n");
		printf("С����ǰ���е�����");
		for (i = q2.head; i <= q2.tail - 1; i++)
			printf("%d", q2.data[i]);
		if (s.top > 0){
			printf("\n�����ϵ�����");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);
		}
		else
			printf("\n�������Ѿ�û����");
	}
	system("pause");
	return 0;
}