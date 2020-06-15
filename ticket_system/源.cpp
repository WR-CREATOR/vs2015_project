#include<stdio.h>
#include<stdlib.h>
#include<time.h>  
#define MAX 99  //���ݸ���

struct people {			//ʵ���ṹ��
	int num;			//����
	char name[20];		//����
	int ticket_ed;		//Ʊ��
} people[MAX];

struct shift			//�೵��Ϣ�ṹ��
{
	int number;			//�೵
	int time;			//����ʱ��
	int count;			//�ؿ���
	int ticket_num;		//����Ʊ��
}shift[3];

int sort = 0;			//�±����
void sale();			//��Ʊ
void Real_name();		//ʵ��
void show_name();		//��ʾ����
void show_ticket();		//��ʾ��Ʊ
void shift_info();		//�г���Ϣ

FILE *px;

int main()				//������
{

	if ((px = fopen("D:\\data09_1.txt", "w")) == NULL) //��data09_1.txt�ļ�
	{
		printf("��ȡ���󣬲��ܴ򿪸��ļ�!!\n");
		system("pause");
		return 0;
	}
	shift_info();
	int choose;
	do {

		system("cls");
		printf("===================ʵ����Ʊϵͳ==================\n");				//��ӡ����
		printf("\t\t1.��Ʊ\n");
		printf("\t\t2.ʵ��ע��\n");
		printf("\t\t3.��ʾ����\n");
		printf("\t\t4.��ʾ��Ʊ\n");
		printf("\t\t5.�˳�\n\n");
		printf("�����빦��ѡ��:");
		scanf("%d", &choose);
		switch (choose)															//���빦��ѡ��
		{
		case 1:sale(); break;													//��Ʊ
		case 2:Real_name(); break;												//ʵ��
		case 3:show_name(); break;												//��ʾ����
		case 4:show_ticket(); break;											//��ʾ��Ʊ
		case 5:break;
		}
	} while (choose != 5);
	fclose(px);																	////�ر�data09_1.txt�ļ�
	system("pause");
	return 0;
}

void Real_name()											//ʵ��ע�Ტ����Ϣ���浽�ļ�
{
	printf("���뿨��");
	scanf("%d", &people[sort].num);
	fprintf(px, "���ţ� %d", people[sort].num);
	printf("��������\n");
	scanf("%s", people[sort].name);
	fprintf(px, "      ������ %s", people[sort].name);
	people[sort].ticket_ed = 0;
	fprintf(px, "      ӵ��Ʊ���� %d", people[sort].ticket_ed);
	sort++;
	fprintf(px, "\n");
}

void shift_info()												//�����Ϣ
{
	shift[1].number = 2;
	shift[1].time = 19;
	shift[1].count = 50;
	shift[1].ticket_num = 0;
	shift[0].number = 1;
	shift[0].time = 6;
	shift[0].count = 50;
	shift[0].ticket_num = 0;
	shift[2].number = 3;
	shift[2].time = 16;
	shift[2].count = 50;
	shift[2].ticket_num = 0;
}

void show_name()												//��ʾ��������
{
	int j;
	printf("\t����\t����\tƱ��\n");
	for (j = 0; j < sort; j++)
	{
		printf("\t%d\t%s\t%d\n", people[j].num, people[j].name, people[j].ticket_ed);
	}
	system("pause");
}

void show_ticket()												//��ʾ��Ʊ
{
	int j;
	printf("\t�೵\tƱ��\n");
	for (j = 0; j < 3; j++)
	{
		printf("\t%d\t%d\n", shift[j].number, shift[j].count - shift[j].ticket_num);
	}
	system("pause");
}

void sale()														//��Ʊ
{
	time_t t;
	t = time(NULL);
	tm tt;
	localtime_s(&tt, &t);
	int loc_time = tt.tm_hour;									//��ȡ��ǰʱ�䣨hour�����ϲ��
	int i;
	int m;
	int  num1;
	int temp = 0;
	printf("\n�����뿨��:");
	scanf("%d", &num1);
	printf("��ǰʱ�䣺%d", loc_time);
	printf("\n��������İ��:");
	scanf("%d", &m);
	if (shift[m-1].time <= loc_time)								//�ж��Ƿ�ʱ,��ʱ������������������ж�
	{
		printf("\n��ʱ�޷�����\n");
	}
	else
	{
		for (i = 0; i < sort; i++)
		{
			if (people[i].num == num1)
			{
				if (people[i].ticket_ed == 1)
				{
					printf(" ֻ�ܹ���һ��Ʊ\n");
				}
				else
				{
					people[i].ticket_ed += 1;
					shift[i].ticket_num += 1;
					temp = 1;
					fprintf(px, "����Ϊ%d��", people[i].num);						//������Ϣ
					fprintf(px, "Ʊ������Ϊ��%d", people[i].ticket_ed);
				}
			}
		}
		if (temp == 0)																//����޴��˻�
		{
			printf("�޴��˻���ʱ�䲻��\n");
		}
	}
	printf("���\n");
	system("pause");


}
