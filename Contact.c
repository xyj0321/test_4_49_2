#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
#include<stdio.h>
void InitContact(struct Contact*ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void AddContact(struct Contact*ps)//ʵ��Add����
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[ps->size].name);

		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));

		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);

		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tel);

		printf("�������ַ��>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}	
}
void ShowContact(const struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i ;
		printf("%-10s\t%-4s\t%-10s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size ; i++)
		{
			printf("%-10s\t%-4d\t%-10s\t%-12s\t%-20s\t\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tel,
				ps->data[i].addr);
		}
	}
}
int FindByName(struct Contact*ps, char name[10])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact*ps)
{
	char name[10];
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		int j=0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearContact(struct Contact*ps)
{
	char name[10];
	printf("������Ҫ�����˵�����\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("�����ڸ���ϵ��\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-10s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-10s\t%-4d\t%-10s\t%-12s\t%-20s\t\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tel,
				ps->data[pos].addr);;
	}
}
void ModContact(struct Contact*ps)
{
	char name[10];
	printf("������Ҫ�޸ĵ�����");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[pos].name);

		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));

		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);

		printf("������绰��>");
		scanf("%s", ps->data[pos].tel);

		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}

}