#pragma once
struct Date {
	UINT32 year;
	UINT32 month;
	UINT32 day;
};

class CalcBirthdayBase
{
	
public:
	std::wstring tgs = L"甲乙丙丁戊己庚辛壬癸";
	std::wstring dzs = L"子丑寅卯辰巳午未申酉戌亥";

	Date begintime, endtime;

	CalcBirthdayBase();
	~CalcBirthdayBase();

	std::wstring calcYear(UINT32 year);
	std::wstring calcMonth(UINT32 year, UINT32 month);
	std::wstring calcDay(UINT32 gzr);
	//判断是否为闰年
	bool IsLeap(UINT32 year);
	//计算时间1-时间2的天数
	UINT32 diffDate(Date begintime, SYSTEMTIME endtime);
};

