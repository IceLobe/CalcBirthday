#include "pch.h"
#include "CalcBirthdayBase.h"
#include "resource.h"




CalcBirthdayBase::CalcBirthdayBase()
{
	tgs = L"甲乙丙丁戊己庚辛壬癸";
	dzs = L"子丑寅卯辰巳午未申酉戌亥";
}

CalcBirthdayBase::~CalcBirthdayBase()
{
}
/*
计算干支年
<param name="year">阳历年</param>
<returns>八字年</returns>
*/
std::wstring CalcBirthdayBase::calcYear(int year)
{
	int tg = (year - 4) % 10;
	int dz = (year - 4) % 12;
    return  tgs.substr(tg, 1) + dzs.substr(dz, 1) + L"年";
}
/*
计算干支月
<param name="year">阳历年</param>
<param name="month">阴历月</param>
<returns>八字月</returns>
*/
std::wstring CalcBirthdayBase::calcMonth(int year, int month)
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
    return tg + dz + L"月";
}
/*
计算干支日
<param name="ctime">阳历日期对象</param>
<returns>八字日</returns>
*/
std::wstring CalcBirthdayBase::calcDay(CTime ctime)
{
    //定义截止时间  
    struct tm deadline_tm;
    deadline_tm.tm_year = 1900 - 1900;
    deadline_tm.tm_mon = 1;
    deadline_tm.tm_mday = 18;

    tm ct;
    ct.tm_year = ctime.GetYear() - 1900;
    ct.tm_mon = ctime.GetMonth();
    ct.tm_mday = ctime.GetDay();

    int seconds = difftime(mktime(&deadline_tm), mktime(&ct));
    int day = seconds / (60 * 60 * 24);
    gzr = day % 60 + 1;
    /*TimeSpan ts = ctime.Subtract(new DateTime(1899, 12, 22));
    int gzr = ts.Days % 60 + 1;
    txtGZMonth.Text = "日柱数为：" + gzr;*/
    std::wstring gz = NULL;
    if (gzr % 10 == 0)
        gz = tgs.substr(9) + dzs.substr(gzr % 12 - 1, 1);
    else
        gz = tgs.substr((gzr % 10) - 1, 1) + dzs.substr((gzr - 1) % 12, 1);
    return gz + L"日";
}
