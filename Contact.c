#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
#include<stdio.h>
void InitContact(struct Contact*ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void AddContact(struct Contact*ps)//实现Add功能
{
	if (ps->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);

		printf("请输入年龄：>");
		scanf("%d", &(ps->data[ps->size].age));

		printf("请输入性别：>");
		scanf("%s", ps->data[ps->size].sex);

		printf("请输入电话：>");
		scanf("%s", ps->data[ps->size].tel);

		printf("请输入地址：>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}	
}
void ShowContact(const struct Contact*ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i ;
		printf("%-10s\t%-4s\t%-10s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入要删除的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		int j=0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearContact(struct Contact*ps)
{
	char name[10];
	printf("请输入要查找人的名字\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("不存在该联系人\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-10s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入要修改的名字");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[pos].name);

		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));

		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);

		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tel);

		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
	}

}