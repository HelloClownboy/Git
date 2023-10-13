#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4013)
#pragma warning(disable:4996)

struct Address
{
	char name[10];
	long long num;
	char relation[10];
	struct Address* next;
};
int count;
struct Address* create()//创建通讯录名单
{
	struct Address* head = NULL;//定义头指针并指向NULL
	struct Address* inew, * end;
	count = 0;
	inew = end = (struct Address*)malloc(sizeof(struct Address));
	printf("电话簿:\n");
	printf("输入姓名、手机号(手机号为0时退出该程序)、关系:\n");
	scanf("%s",&inew->name);
	scanf("%lld", &inew->num);
	scanf("%s", &inew->relation);
	while (inew->num != 0)//手机号为0时退出该程序
	{
		count++;
		if (count == 1)//只有一个节点时
		{
			inew->next = head;//新节点的指针指向NULL
			end = inew;
			head = inew;
		}
		else
		{
			inew->next = NULL;
			end->next = inew;
			end = inew;
		}
		inew= (struct Address*)malloc(sizeof(struct Address));
		scanf("%s", &inew->name);
		scanf("%lld", &inew->num);
		scanf("%s", &inew->relation);
	}
	free(inew);
	return head;//返回链表的头指针
}
struct Address* insert(struct Address* head)//插入新的联系人
{
	struct Address* renew;
	renew= (struct Address*)malloc(sizeof(struct Address));
	printf("输入新添加的姓名、手机号、关系:\n");
	printf("姓名:");
	scanf("%s", &renew->name);
	printf("手机号:");
	scanf("%lld", &renew->num);
	printf("关系:");
	scanf("%s", &renew->relation);
	//头节点位置插入节点
	renew->next = head;
	head = renew;
	return head;//返回链表的头指针
}
struct Address*idelete(struct Address* head, int index)//删除特定序号联系人
{
	int i;
	struct Address* point, * previous;
	point = head;
	previous = point;
	if (index == 1)//删除序号为1
	{
		head = point->next;
	}
	else
	{
		for (i = 1; i < index; i++)// 找到序号等于index的节点
		{
			previous = point;//previous表示待删节点的前一个节点
			point = point->next;
		}
		previous->next = point->next;//删除point节点
		free(point);
	}
	return head;//返回链表的头指针
}
void print(struct Address* head)//打印通讯录名单
{
	int num = 1;
	struct Address* instead;
	instead = head;//从头指针开始进行打印
	while (instead != NULL)
	{
		printf("%d:", num);
		printf("姓名:%s\n", instead->name);
		printf("手机号:%lld\n", instead->num);
		printf("关系:%s\n", instead->relation);
		printf("\n");
		printf("\n");
		instead = instead->next;
		num++;
	}
}
struct Address*change(struct Address* head, int index)//改变通讯录人员信息
{
	int i;
	struct Address* point, * renew;
	renew = (struct Address*)malloc(sizeof(struct Address));
	point = head;
	printf("输入需更改的姓名、手机号、关系:\n");
	printf("新的姓名:");
	scanf("%s", &renew->name);
	printf("新的手机号:");
	scanf("%lld", &renew->num);
	printf("新的关系:");
	scanf("%s", &renew->relation);
	//找到需改变的节点
	if (index == 1)
	{
		point = head;
	}
	else
	{
		for (i = 1; i < index; i++)
		{
			point = point->next;
		}
	}
	//将renew节点上的数据部分复制到point上
	strcpy(point->name,renew->name);
	point->num = renew->num;
	strcpy(point->relation ,renew->relation);
	free(renew);
	return head;//返回链表的头指针
}
struct Address* search(struct Address* head)//查找信息
{
	char searchname[10] = { 0 };
	struct Address* point;
	point = head;
	printf("输入你想搜索的人名,或输入0跳出:\n");
	scanf("%s", searchname);
	while (point != NULL)
	{
		if (strcmp(searchname, point->name) == 0)//如果要查找号码或关系，同理
		{
			printf("姓名:%s\n", point->name);
			printf("号码:%lld\n", point->num);
			printf("关系:%s\n", point->relation);
			break;
		}
		point = point->next;
	}
	if (point == NULL)
	{
		printf("查无此人!");
	}
	printf("\n");
	return head;
}
int main()
{
	int number;
	int choice;
	struct Address* head;
	head = create();
	print(head);//打印通讯录
	do//进行功能的选择
	{
		printf("输入1时添加信息，输入2时删除信息，输入3时查询信息，输入4时修改信息，输入5查询人名,输入0时退出程序\n");
		scanf("%d", &choice);
		printf("\n");
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("\n输入你想添加的账户:\n");
			do
			{
				head = insert(head);
				printf("\n");
				print(head);
				printf("按任意1=9数字继续输入你想添加的账户,或输入0跳出:\n");
				scanf("%d", &number);
			} while (number != 0);
			break;
		case 2:
			printf("输入你想删除的账户的序号(单次删除,输入0时跳出):\n");
			scanf("%d", &number);
			while (number != 0)
			{
				head = idelete(head, number);
				printf("\n");
				print(head);
				printf("按任意1-9数字继续输入你想删除的账户的序号,或输入0跳出:\n");
				scanf("%d", &number);
			}
			break;
		case 3:
			print(head);
			break;
		case 4:
			printf("输入你想更改的账户的序号(单次删除,输入0时跳出):\n");
			scanf("%d", &number);
			while (number != 0)
			{
				head = change(head, number);
				printf("\n");
				printf("按任意1-9数字继续输入你想更改的账户的序号,或输入0跳出:\n");
				scanf("%d", &number);
			}
			break;
		case 5:
			head = search(head);
			break;
		}
	} while (choice != 0);
	return 0;
}