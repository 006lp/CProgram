#include <stdio.h>

// 检查一个年份是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

//定义每月天数
static int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//计算日期距离年初时间
int dayBefore(int year,int month,int day)
{
    int before = 0;
    for(int i=0;i<month-1;i++)
    {
        before += monthDays[i];
        if(i ==2 && isLeapYear(year))
        {
            before ++;
        }
    }
    before += day ;
    return before ;
}

int main()
{
    int birthyear , birthmonth , birthday , nowyear , nowmonth , nowday , date;
    // 提示用户输入出生日期
    printf("输入你的出生日期（格式为 年-月-日）：\n");
    printf("例如：2024-5-22\n");
    scanf("%d-%d-%d", &birthyear, &birthmonth, &birthday);

    // 计算出生天数
    int birthDays = dayBefore(birthyear, birthmonth, birthday);

    //判断出生时间合法
    if(birthyear<=0 || (birthmonth >12 && birthmonth < 1) || (birthday > monthDays[birthmonth] && birthday < 1))
    {
        printf("您输入的日期有误。\n");
        return 0;
    }  

    // 提示用户输入现在日期
    printf("输入现在日期（格式为 年-月-日）：\n");
    printf("例如：2024-5-22\n");
    scanf("%d-%d-%d", &nowyear, &nowmonth, &nowday);

    //判断现在时间合法
    if(nowyear<=0 || (nowmonth >12 && nowmonth < 1) || (nowday > monthDays[nowmonth] && nowday < 1))
    {
        printf("您输入的日期有误。\n");
        return 0;
    } 

    //计算现在日期距离年初时间
    int Now = dayBefore(nowyear, nowmonth, nowday);

    //计算整年数并考虑出生时间与现在时间大小
    int FullYear = (nowyear - birthyear)*365 ;
    if(nowyear == birthyear && (birthmonth < nowmonth || (birthmonth = nowmonth && birthday <= nowday)))
    {
        date = Now - birthDays;
    }
    else if(nowyear > birthyear)
    {
        for(int i = birthyear ; i <= nowyear ; i++)
        {
            if(isLeapYear(i))
            {
                FullYear ++;
            }
        }
        date = FullYear - birthDays + Now -1;
    }
    else
    {
        printf("你是怎么做到出生日期比现在时间还晚的？");
        return 0;
    }
    
    // 打印出生天数
    printf("你的出生天数为：%d\n", date);
    return 0;
}