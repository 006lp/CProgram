#include <stdio.h>

// 检查一个年份是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 定义每月天数
static int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 计算日期距离年初的天数
int dayOfYear(int year, int month, int day) {
    int days = day;
    for (int i = 0; i < month - 1; i++) {
        days += monthDays[i];
    }
    if (month > 2 && isLeapYear(year)) {
        days++;
    }
    return days;
}

// 检查日期合法性
int isValidDate(int year, int month, int day) {
    if (year <= 0 || month < 1 || month > 12 || day < 1 || day > monthDays[month - 1]) {
        if (month == 2 && day == 29 && isLeapYear(year)) {
            return 1;
        }
        return 0;
    }
    return 1;
}

int main() {
    int birthYear, birthMonth, birthDay, nowYear, nowMonth, nowDay;
    
    // 提示用户输入出生日期
    printf("输入你的出生日期（格式为 年-月-日）：\n例如：2024-5-22\n");
    if (scanf("%d-%d-%d", &birthYear, &birthMonth, &birthDay) != 3 || !isValidDate(birthYear, birthMonth, birthDay)) {
        printf("您输入的日期有误。\n");
        return 1;
    }
    
    // 提示用户输入现在日期
    printf("输入现在日期（格式为 年-月-日）：\n");
    printf("例如：2024-5-22\n");
    if (scanf("%d-%d-%d", &nowYear, &nowMonth, &nowDay) != 3 || !isValidDate(nowYear, nowMonth, nowDay)) {
        printf("您输入的日期有误。\n");
        return 1;
    }
    
    if (nowYear < birthYear || (nowYear == birthYear && nowMonth < birthMonth) || 
        (nowYear == birthYear && nowMonth == birthMonth && nowDay < birthDay)) {
        printf("你是怎么做到出生日期比现在时间还晚的？\n");
        return 1;
    }

    int birthDays = dayOfYear(birthYear, birthMonth, birthDay);
    int nowDays = dayOfYear(nowYear, nowMonth, nowDay);
    
    int totalDays = (nowYear - birthYear) * 365;
    for (int i = birthYear; i < nowYear; i++) {
        if (isLeapYear(i)) {
            totalDays++;
        }
    }

    totalDays = totalDays - birthDays + nowDays;

    // 打印出生天数
    printf("你的出生天数为：%d\n", totalDays);
    
    return 0;
}
