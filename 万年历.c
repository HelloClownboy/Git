#include <stdio.h>
#pragma warning(disable:4996)

int SpecialYear(int year) // 判断某年是否为闰年
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) // 获取某月的天数
{
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && SpecialYear(year)) //判断闰年
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
        printf("请输入年份（1-2023）：");
        scanf("%d", &year);
        printf("请输入月份（1-12）：");
        scanf("%d", &month);
        printf("请输入日(1-31):");
        scanf("%d", &day);
        if (year < 1 || month < 1 || month > 12 || day>31) //判断数据正误
        {
            printf("输入无效，请重新输入年份和月份。\n");
            continue;
        }
        int totalDays = getDaysInMonth(year, month);
        printf("\n日 一 二 三 四 五 六\n");
        int firstday = 1; // 公元1年1月1日为星期一
        for (int i = 1; i < year; i++)
        {
            firstday += SpecialYear(i) ? 366 : 365;
        }
        for (int i = 1; i < month; i++)
        {
            firstday += getDaysInMonth(year, i);//所得所求月份之前的总天数
        }
        firstday %= 7; // 计算月份第一天是星期几
        int dayOfMonth = 1;// 下面为打印月份的日历表
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 7; j++) 
            {
                if (i == 0 && j < firstday)
                {
                    printf("   "); // 打印空格占位
                }
                else if (dayOfMonth <= totalDays) 
                {
                    if (dayOfMonth == day) 
                    {
                        printf("*%2d ", dayOfMonth); // 当前日期用星号标记
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
        printf("输入1重新查看日期，输入0退出系统:");
        scanf("%d", &number);
        if (number == 1)
        {
            printf("\n");
        }
        if (number == 0)
        {
            printf("退出成功!");
            break;
        }
    }
    return 0;
}