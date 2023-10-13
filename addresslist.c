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
struct Address* create()//����ͨѶ¼����
{
	struct Address* head = NULL;//����ͷָ�벢ָ��NULL
	struct Address* inew, * end;
	count = 0;
	inew = end = (struct Address*)malloc(sizeof(struct Address));
	printf("�绰��:\n");
	printf("�����������ֻ���(�ֻ���Ϊ0ʱ�˳��ó���)����ϵ:\n");
	scanf("%s",&inew->name);
	scanf("%lld", &inew->num);
	scanf("%s", &inew->relation);
	while (inew->num != 0)//�ֻ���Ϊ0ʱ�˳��ó���
	{
		count++;
		if (count == 1)//ֻ��һ���ڵ�ʱ
		{
			inew->next = head;//�½ڵ��ָ��ָ��NULL
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
	return head;//���������ͷָ��
}
struct Address* insert(struct Address* head)//�����µ���ϵ��
{
	struct Address* renew;
	renew= (struct Address*)malloc(sizeof(struct Address));
	printf("��������ӵ��������ֻ��š���ϵ:\n");
	printf("����:");
	scanf("%s", &renew->name);
	printf("�ֻ���:");
	scanf("%lld", &renew->num);
	printf("��ϵ:");
	scanf("%s", &renew->relation);
	//ͷ�ڵ�λ�ò���ڵ�
	renew->next = head;
	head = renew;
	return head;//���������ͷָ��
}
struct Address*idelete(struct Address* head, int index)//ɾ���ض������ϵ��
{
	int i;
	struct Address* point, * previous;
	point = head;
	previous = point;
	if (index == 1)//ɾ�����Ϊ1
	{
		head = point->next;
	}
	else
	{
		for (i = 1; i < index; i++)// �ҵ���ŵ���index�Ľڵ�
		{
			previous = point;//previous��ʾ��ɾ�ڵ��ǰһ���ڵ�
			point = point->next;
		}
		previous->next = point->next;//ɾ��point�ڵ�
		free(point);
	}
	return head;//���������ͷָ��
}
void print(struct Address* head)//��ӡͨѶ¼����
{
	int num = 1;
	struct Address* instead;
	instead = head;//��ͷָ�뿪ʼ���д�ӡ
	while (instead != NULL)
	{
		printf("%d:", num);
		printf("����:%s\n", instead->name);
		printf("�ֻ���:%lld\n", instead->num);
		printf("��ϵ:%s\n", instead->relation);
		printf("\n");
		printf("\n");
		instead = instead->next;
		num++;
	}
}
struct Address*change(struct Address* head, int index)//�ı�ͨѶ¼��Ա��Ϣ
{
	int i;
	struct Address* point, * renew;
	renew = (struct Address*)malloc(sizeof(struct Address));
	point = head;
	printf("��������ĵ��������ֻ��š���ϵ:\n");
	printf("�µ�����:");
	scanf("%s", &renew->name);
	printf("�µ��ֻ���:");
	scanf("%lld", &renew->num);
	printf("�µĹ�ϵ:");
	scanf("%s", &renew->relation);
	//�ҵ���ı�Ľڵ�
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
	//��renew�ڵ��ϵ����ݲ��ָ��Ƶ�point��
	strcpy(point->name,renew->name);
	point->num = renew->num;
	strcpy(point->relation ,renew->relation);
	free(renew);
	return head;//���������ͷָ��
}
struct Address* search(struct Address* head)//������Ϣ
{
	char searchname[10] = { 0 };
	struct Address* point;
	point = head;
	printf("������������������,������0����:\n");
	scanf("%s", searchname);
	while (point != NULL)
	{
		if (strcmp(searchname, point->name) == 0)//���Ҫ���Һ�����ϵ��ͬ��
		{
			printf("����:%s\n", point->name);
			printf("����:%lld\n", point->num);
			printf("��ϵ:%s\n", point->relation);
			break;
		}
		point = point->next;
	}
	if (point == NULL)
	{
		printf("���޴���!");
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
	print(head);//��ӡͨѶ¼
	do//���й��ܵ�ѡ��
	{
		printf("����1ʱ�����Ϣ������2ʱɾ����Ϣ������3ʱ��ѯ��Ϣ������4ʱ�޸���Ϣ������5��ѯ����,����0ʱ�˳�����\n");
		scanf("%d", &choice);
		printf("\n");
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("\n����������ӵ��˻�:\n");
			do
			{
				head = insert(head);
				printf("\n");
				print(head);
				printf("������1=9���ּ�������������ӵ��˻�,������0����:\n");
				scanf("%d", &number);
			} while (number != 0);
			break;
		case 2:
			printf("��������ɾ�����˻������(����ɾ��,����0ʱ����):\n");
			scanf("%d", &number);
			while (number != 0)
			{
				head = idelete(head, number);
				printf("\n");
				print(head);
				printf("������1-9���ּ�����������ɾ�����˻������,������0����:\n");
				scanf("%d", &number);
			}
			break;
		case 3:
			print(head);
			break;
		case 4:
			printf("����������ĵ��˻������(����ɾ��,����0ʱ����):\n");
			scanf("%d", &number);
			while (number != 0)
			{
				head = change(head, number);
				printf("\n");
				printf("������1-9���ּ�������������ĵ��˻������,������0����:\n");
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