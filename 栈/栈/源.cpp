#include<stdio.h>
#include<Windows.h>
int main(){
	char a[100],s[100];
	int head=0,len;
	int mid, i;
	gets_s(a);
	len = strlen(a);
	if (len % 2 == 0)
		mid = len / 2;
	else
		mid = len / 2 + 1;
	for (i = 0; i <3; i++){
		s[head] = a[i];
		//printf("%c", a[head]);
		head++;
		//printf("%d", head);//headµÄ¹ø±³ºÃ head=3;
	}
	for (i = mid-1; i <len; i++){
		if (a[i] == s[head-1]){
			head--;
			//printf("%d", head);
		}
	}
	if (head == 0)
		printf("OK");
	system("pause");
}