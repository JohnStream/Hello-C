#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
struct node{
	int data;
	struct node*next;
};
int main(){
	struct node *head, *p=NULL, *q=NULL, *t=NULL;
	int i, n, a;
	scanf_s("%d", &n);
	head = NULL;
	for (i = 1 ; i <= n; i++){
		scanf_s("%d",&a);
		p = (struct node*)malloc(sizeof(struct node));
		p->data=a;
		p->next = NULL;
		
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	}
	t = head;
	while (t != NULL){
		printf("%d", t->data);
		t = t->next;
	}
	printf("\nplease input one number");
	scanf_s("%d", &a);
	t = head;
	while (t != NULL){
		if (t->next == NULL || t->next->data > a){
			p = (struct node*)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}
	t = head;
	while (t != NULL){
		printf("%d", t->data);
		t = t->next;
	}
	system("pause");
	return 0;
	
}
