#include "pch.h"
#include "CalcBirthdayBase.h"




CalcBirthdayBase::CalcBirthdayBase()
{
	tgs = L"¼×ÒÒ±û¶¡Îì¼º¸ýÐÁÈÉ¹ï";
	dzs = L"×Ó³óÒúÃ®³½ËÈÎçÎ´ÉêÓÏÐçº¥";

    begintime.year = 1899;
    begintime.month = 11;
    begintime.day = 30;

}

CalcBirthdayBase::~CalcBirthdayBase()
{
}

std::wstring CalcBirthdayBase::calcYear(UINT32 year)
{
	int tg = (year - 4) % 10;
	int dz = (year - 4) % 12;
    return  tgs.substr(tg, 1) + dzs.substr(dz, 1) + L"Äê";
}

std::wstring CalcBirthdayBase::calcMonth(UINT32 year, UINT32 month)
{
    std::wstring tg = L"", dz = L"";
    int num = (year - 4) % 5;
    switch (num)
    {
    case 0:
        tg = tgs.substr((month + 1) % 10, 1);
        break;
    case 1:
        tg = tgs.substr((month + 3) % 10, 1);
        break;
    case 2:
        tg = tgs.substr((month + 5) % 10, 1);
        break;
    case 3:
        tg = tgs.substr((month + 7) % 10, 1);
        break;
    case 4:
        tg = tgs.substr((month - 1) % 10, 1);
        break;
    default:
        break;
    }
    dz = dzs.substr((month + 1) % 12, 1);
    return tg + dz + L"ÔÂ";
}

std::wstring CalcBirthdayBase::calcDay(UINT32 gzr)
{
    std::wstring gz = L"";
    if (gzr % 10 == 0)
        gz = tgs.substr(9, 1) + dzs.substr(gzr % 12, 1);
    else
        gz = tgs.substr(gzr % 10 - 1, 1) + dzs.substr(gzr % 12 - 1, 1);
    return gz + L"ÈÕ";
}
//ÅÐ¶ÏÊÇ·ñÎªÈòÄê
bool CalcBirthdayBase::IsLeap(UINT32 year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    return false;
}

UINT32 CalcBirthdayBase::diffDate(Date begintime, SYSTEMTIME endtime)
{
    int days;
    int months, years;
    int tmpyear, leapyear;
    short monthday[2][12] = {
    {31,28,31,30,31,30,31,30,31,30,31},
    {31,29,31,30,31,30,31,30,31,30,31}
    };
    if (IsLeap(endtime.wYear)) {
        leapyear = 1;
    }
    else {
        leapyear = 0;
    }
    years = endtime.wYear - begintime.year;
    months = endtime.wMonth - begintime.month;
    days = endtime.wDay - begintime.day;
    tmpyear = begintime.year;
    while (years > 0) {
        if (IsLeap(tmpyear))
            days += 366;
        else
            days += 365;
        tmpyear++;
        years--;
    }
    if (months > 0) {
        while (months-- > 0) {
            days += monthday[leapyear][begintime.month++ - 1];
        }
    }
    else {
        while (months++ < 0) {
            begintime.month--;
            days -= monthday[leapyear][begintime.month - 1];
        }
    }
    return days;
}

