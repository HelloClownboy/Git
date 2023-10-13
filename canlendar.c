#include <stdio.h>
#pragma warning(disable:4996)

int SpecialYear(int year) // �ж�ĳ���Ƿ�Ϊ����
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) // ��ȡĳ�µ�����
{
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && SpecialYear(year)) //�ж�����
    {
        return 29;
    }
    else
    {
        return daysInMonth[month];
    }
}

int main()
{
    int number;
    int year, month, day = 0;
    while (1)
    {
        printf("��������ݣ�1-2023����");
        scanf("%d", &year);
        printf("�������·ݣ�1-12����");
        scanf("%d", &month);
        printf("��������(1-31):");
        scanf("%d", &day);
        if (year < 1 || month < 1 || month > 12 || day>31) //�ж���������
        {
            printf("������Ч��������������ݺ��·ݡ�\n");
            continue;
        }
        int totalDays = getDaysInMonth(year, month);
        printf("\n�� һ �� �� �� �� ��\n");
        int firstday = 1; // ��Ԫ1��1��1��Ϊ����һ
        for (int i = 1; i < year; i++)
        {
            firstday += SpecialYear(i) ? 366 : 365;
        }
        for (int i = 1; i < month; i++)
        {
            firstday += getDaysInMonth(year, i);//���������·�֮ǰ��������
        }
        firstday %= 7; // �����·ݵ�һ�������ڼ�
        int dayOfMonth = 1;// ����Ϊ��ӡ�·ݵ�������
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                if (i == 0 && j < firstday)
                {
                    printf("   "); // ��ӡ�ո�ռλ
                }
                else if (dayOfMonth <= totalDays) 
                {
                    if (dayOfMonth == day) 
                    {
                        printf("*%2d ", dayOfMonth); // ��ǰ�������Ǻű��
                    }
                    else 
                    {
                        printf("%2d ", dayOfMonth);
                    }
                    dayOfMonth++;
                }
            }
            printf("\n");
        }
        printf("\n");
        printf("����1���²鿴���ڣ�����0�˳�ϵͳ:");
        scanf("%d", &number);
        if (number == 1)
        {
            printf("\n");
        }
        if (number == 0)
        {
            printf("�˳��ɹ�!");
            break;
        }
    }
    return 0;
}