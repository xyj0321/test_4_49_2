//通讯录成员类型
#define MAX 1000
#include<string.h>
struct Peoinfo
{
	char name[10];
	int age;
	char sex[10];
	char tel[20];
	char addr[30];
};
struct Contact
{
	struct Peoinfo data[MAX];
	int size;
};
void InitContact(struct Contact*ps);
void AddContact(struct Contact*ps);
void ShowContact(const struct Contact*ps);
void DelContact(struct Contact*ps);
void SearContact(struct Contact*ps);
void ModContact(struct Contact*ps);