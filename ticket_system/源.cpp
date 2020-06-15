#include<stdio.h>
#include<stdlib.h>
#include<time.h>  
#define MAX 99  //数据个数

struct people {			//实名结构体
	int num;			//卡号
	char name[20];		//姓名
	int ticket_ed;		//票数
} people[MAX];

struct shift			//班车信息结构体
{
	int number;			//班车
	int time;			//发车时间
	int count;			//载客量
	int ticket_num;		//已售票数
}shift[3];

int sort = 0;			//下标变量
void sale();			//售票
void Real_name();		//实名
void show_name();		//显示姓名
void show_ticket();		//显示余票
void shift_info();		//列车信息

FILE *px;

int main()				//主函数
{

	if ((px = fopen("D:\\data09_1.txt", "w")) == NULL) //打开data09_1.txt文件
	{
		printf("读取错误，不能打开该文件!!\n");
		system("pause");
		return 0;
	}
	shift_info();
	int choose;
	do {

		system("cls");
		printf("===================实名售票系统==================\n");				//打印界面
		printf("\t\t1.售票\n");
		printf("\t\t2.实名注册\n");
		printf("\t\t3.显示姓名\n");
		printf("\t\t4.显示余票\n");
		printf("\t\t5.退出\n\n");
		printf("请输入功能选项:");
		scanf("%d", &choose);
		switch (choose)															//输入功能选项
		{
		case 1:sale(); break;													//售票
		case 2:Real_name(); break;												//实名
		case 3:show_name(); break;												//显示姓名
		case 4:show_ticket(); break;											//显示余票
		case 5:break;
		}
	} while (choose != 5);
	fclose(px);																	////关闭data09_1.txt文件
	system("pause");
	return 0;
}

void Real_name()											//实名注册并将信息保存到文件
{
	printf("输入卡号");
	scanf("%d", &people[sort].num);
	fprintf(px, "卡号： %d", people[sort].num);
	printf("输入姓名\n");
	scanf("%s", people[sort].name);
	fprintf(px, "      姓名： %s", people[sort].name);
	people[sort].ticket_ed = 0;
	fprintf(px, "      拥有票数： %d", people[sort].ticket_ed);
	sort++;
	fprintf(px, "\n");
}

void shift_info()												//班次信息
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

void show_name()												//显示姓名函数
{
	int j;
	printf("\t卡号\t姓名\t票数\n");
	for (j = 0; j < sort; j++)
	{
		printf("\t%d\t%s\t%d\n", people[j].num, people[j].name, people[j].ticket_ed);
	}
	system("pause");
}

void show_ticket()												//显示余票
{
	int j;
	printf("\t班车\t票数\n");
	for (j = 0; j < 3; j++)
	{
		printf("\t%d\t%d\n", shift[j].number, shift[j].count - shift[j].ticket_num);
	}
	system("pause");
}

void sale()														//买票
{
	time_t t;
	t = time(NULL);
	tm tt;
	localtime_s(&tt, &t);
	int loc_time = tt.tm_hour;									//读取当前时间（hour）网上查的
	int i;
	int m;
	int  num1;
	int temp = 0;
	printf("\n请输入卡号:");
	scanf("%d", &num1);
	printf("当前时间：%d", loc_time);
	printf("\n请输入买的班次:");
	scanf("%d", &m);
	if (shift[m-1].time <= loc_time)								//判断是否超时,超时则结束，不进行下面判断
	{
		printf("\n超时无法购买\n");
	}
	else
	{
		for (i = 0; i < sort; i++)
		{
			if (people[i].num == num1)
			{
				if (people[i].ticket_ed == 1)
				{
					printf(" 只能购买一张票\n");
				}
				else
				{
					people[i].ticket_ed += 1;
					shift[i].ticket_num += 1;
					temp = 1;
					fprintf(px, "卡号为%d的", people[i].num);						//更新信息
					fprintf(px, "票数更新为：%d", people[i].ticket_ed);
				}
			}
		}
		if (temp == 0)																//检测无此账户
		{
			printf("无此账户或时间不对\n");
		}
	}
	printf("完成\n");
	system("pause");


}
