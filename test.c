#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
#include<stdio.h>
void menu()
{
	printf("***************************************\n");
	printf("*****1.Add              2. Del   *****\n");
	printf("*****3.Ser               4.Modify *****\n");
	printf("*****5.Show              0.EXIT   *****\n");
	printf("***************************************\n");
}
enum option
{
	EXIT,
	ADD,
	DELATE,
	SEARCH,
	MODIFY,
	SHOW
};
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELATE:
			DelContact(&con);
			break;
		case SEARCH:
			SearContact(&con);
			break;
		case MODIFY:
			ModContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}