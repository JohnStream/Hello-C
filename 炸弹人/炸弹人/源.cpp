/*ը������Ϸ
#----ǽ
.----�յ�
G----����
*/
#include<stdio.h>
#include<windows.h>
int main(){
	char a[20][21];//��ͼ���ֵ
	int i, j, sum, map = 0, p, q, x, y, n, m;
	scanf_s("%d %d", &n, &m);//n---�� m---��
	for (i = 0; i <= n - 1; i++){//���ַ����޷����������ַ���
		scanf_s("%s", a[i]);
	}
	//ѭ��������ͼÿһ����
	for (i = 0; i <= n - 1; i++){
		for (j = 0; j <= m - 1; j++){
			if (a[i][j] == '.'){//�յز��ܰ����ӵ�
				sum = 0;//sum---������˵���������ʼ��
				//����ǰ����i��j��ֵ��x,y,�������������ĸ�����ı����ֱ�ͳ��
				x = i; y = j;
				while (a[x][y] != '#'){//�ж��ǲ���ǽ
					if (a[x][y] == 'G')
						sum++;//ͳ�Ƶ�ǰ��
					x--;//����ͳ��
				}
				//����ͳ��
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					x++;
				}
				//����ͳ��
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					y--;
				}
				//����ͳ��
				x = i;
				y = j;
				while (a[x][y] != '#'){
					if (a[x][y] == 'G')
						sum++;
					y++;
				}
				if (sum > map){//����������������������map,�����map
					map = sum;
					//p,q��¼��������
					p = i;
					q = j;
				}
			}
		}
	}
	printf("��ը��������(%d,%d),����������%d������\n", p, q, map);
	system("pause");
}