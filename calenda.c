#include <stdio.h>
#pragma warning(disable:4996)

int isLeapYear(int year) // 判断某年是否为闰年
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) // 获取某月的天数
{
    int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) //判断闰年
    {
        return 29;
    }
    else
    {
        return daysPerMonth[month];
    }
}

int main()
{
    int year, month, day = 0;
    while (1)
    {
        printf("请输入年份（1-2023）：");
        scanf("%d", &year);
        printf("请输入月份（1-12）：");
        scanf("%d", &month);
        printf("请输入日(1-31),输入0退出\n");
        scanf("%d", &day);
        if (year < 1 || month < 1 || month > 12 || day>31) //判断数据正误
        {
            printf("输入无效，请重新输入年份和月份。\n");
            continue;
        }
        int totalDays = getDaysInMonth(year, month);
        printf("\n日 一 二 三 四 五 六\n");
        int firstDayOfWeek = 1; // 假设第一天是星期一
        for (int i = 1; i < year; i++)
        {
            firstDayOfWeek += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 1; i < month; i++)
        {
            firstDayOfWeek += getDaysInMonth(year, i);//所得所求月份之前的总天数
        }
        firstDayOfWeek %= 7; // 计算月份第一天是星期几
        int dayOfMonth = 1;// 下面为打印月份的日历表
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (i == 0 && j < firstDayOfWeek)
                {
                    printf("   "); // 打印空格占位
                }
                else if (dayOfMonth <= totalDays) {
                    if (dayOfMonth == day) {
                        printf("*%2d ", dayOfMonth); // 当前日期用星号标记
                    }
                    else {
                        printf("%2d ", dayOfMonth);
                    }
                    dayOfMonth++;
                }
            }
            printf("\n");
        }
        printf("\n");
        if (day == 0)
        {
            break;
        }
    }
    return 0;
}