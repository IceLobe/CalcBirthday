#include "pch.h"
#include "CalcBirthdayBase.h"
#include "resource.h"




CalcBirthdayBase::CalcBirthdayBase()
{
	tgs = L"甲乙丙丁戊己庚辛壬癸";
	dzs = L"子丑寅卯辰巳午未申酉戌亥";

	begintime.year = 1899;
	begintime.month = 12;
	begintime.day = 20;
}

CalcBirthdayBase::~CalcBirthdayBase()
{
}

Date CalcBirthdayBase::GetLunarCalendarMonth(SYSTEMTIME stime)
{
	try
	{
		Date dt;
		INT32 year = stime.wYear;
		INT32 month = stime.wMonth; ;
		INT32 day = stime.wDay;

		INT32 nTheDate;
		INT32 nIsEnd = 0, k = 0, m = 0, n = 0, nBit = 0, i = 0;
		std::wstring calendar = L"";
		//计算到初始时间1921年2月8日的天数：1921-2-8(正月初一)
		nTheDate = (year - 1921) * 365 + (year - 1921) / 4 + day + MonthAdd[month - 1] - 38;
		//判断是否为闰年并且月份大于2月
		if ((year % 4 == 0) && (month > 2))
			nTheDate += 1;
		//计算天干，地支，月，日
		while (nIsEnd != 1)
		{
			if (LunarData[m] < 4095)
				k = 11;
			else
				k = 12;
			n = k;
			while (n >= 0)
			{
				//获取LunarData[m]的第n个二进制位的值
				nBit = LunarData[m];
				for (i = 0; i < n; i++)
					nBit = nBit / 2;
				nBit = nBit % 2;
				if (nTheDate <= (29 + nBit))
				{
					nIsEnd = 1;
					break;
				}
				nTheDate = nTheDate - 29 - nBit;
				n -= 1;
			}
			if (nIsEnd == 1)
				break;
			m = m + 1;
		}
		year = 1921 + m;
		month = k - n + 1;
		day = nTheDate;

		//#region 格式化日期显示为三月廿四
		if (k == 12)
		{
			if (month == LunarData[m] / 65536 + 1)
				month = 1 - month;
			else if (month > LunarData[m] / 65536 + 1)
				month = month - 1;
		}
		//农历月
		if (month < 1)
		{
			calendar += L"闰" + months[abs(month) - 1];
			month = abs(month);
		}
		else
		{
			calendar += months[month - 1];
		}
		dt.month = month;
		dt.day = day;
		dt.lunarCalendar = calendar + days[day - 1];
		return dt;
	}
	catch (const std::exception&)
	{
		return Date();
	}
}

/*
计算干支年
<param name="year">阳历年</param>
<returns>八字年</returns>
*/
std::wstring CalcBirthdayBase::calcYear(INT32 year)
{
	int tg = (year - 4) % 10;
	int dz = (year - 4) % 12;
	return  tgs.substr(tg, 1) + dzs.substr(dz, 1);
}

/*
计算干支月
<param name="year">阳历年</param>
<param name="month">阴历月</param>
<returns>八字月</returns>
*/
std::wstring CalcBirthdayBase::calcMonth(INT32 year, INT32 month)
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
	return tg + dz;
}

/*
计算干支日
<param name="gzr">日柱数</param>
<returns>八字日</returns>
*/
std::wstring CalcBirthdayBase::calcDay(INT32 gzr)
{
	std::wstring gz = L"";
	if (gzr % 10 == 0)
	{
		gz = tgs.substr(9, 1) + dzs.substr(gzr % 12, 1);
	}
	if (gzr % 12 == 0)
	{
		gz = tgs.substr(gzr % 10, 1) + dzs.substr(dzs.length() - 1, 1);
	}
	if (gzr != 0 && gzr % 10 != 0 && gzr % 12 != 0)
	{
		gz = tgs.substr(gzr % 10, 1) + dzs.substr(gzr % 12, 1);
	}
	if (gzr == 0)
	{
		gz = tgs.substr(gzr % 10, 1) + dzs.substr(gzr % 12, 1);
	}
	return gz;
}
//判断是否为闰年
bool CalcBirthdayBase::IsLeap(INT32 year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

INT32 CalcBirthdayBase::diffDate(Date begintime, SYSTEMTIME endtime)
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

void CalcBirthdayBase::_SetClipboardData(CString buff)
{
	int buff_size = buff.GetLength();
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		HANDLE clipbuffer = GlobalAlloc(GMEM_DDESHARE, (buff_size + 1) * 2);
		if (!clipbuffer)
		{
			CloseClipboard();
			return;
		}
		char* buffer = (char*)GlobalLock(clipbuffer);
		memset(buffer, 0, (buff_size + 1) * 2);
		memcpy_s(buffer, buff_size * 2, buff.GetBuffer(0), buff_size * 2);
		buff.ReleaseBuffer();
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_UNICODETEXT, clipbuffer);
		CloseClipboard();
	}
}

