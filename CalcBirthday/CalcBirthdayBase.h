#pragma once
struct Date {
	INT32 year = 0;
	INT32 month = 0;
	INT32 day = 0;
	std::wstring lunarCalendar = L"";
};

class CalcBirthdayBase
{
	
public:
	std::wstring tgs = L"甲乙丙丁戊己庚辛壬癸";
	std::wstring dzs = L"子丑寅卯辰巳午未申酉戌亥";

	std::wstring months[12] = { L"正月", L"二月", L"三月", L"四月", L"五月", L"六月", L"七月", L"八月", L"九月", L"十月", L"冬月", L"腊月" };
	std::wstring days[30] = { L"初一", L"初二", L"初三", L"初四", L"初五", L"初六", L"初七", L"初八", L"初九", L"初十", L"十一", L"十二", L"十三", L"十四", L"十五", L"十六", L"十七", L"十八", L"十九", L"二十", L"廿一", L"廿二", L"廿三", L"廿四", L"廿五", L"廿六", L"廿七", L"廿八", L"廿九", L"三十" };

	INT32 MonthAdd[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	INT32 LunarData[100] = { 2635,333387,1701,1748,267701,694,2391,133423,1175,396438
			,3402,3749,331177,1453,694,201326,2350,465197,3221,3402
			,400202,2901,1386,267611,605,2349,137515,2709,464533,1738
			,2901,330421,1242,2651,199255,1323,529706,3733,1706,398762
			,2741,1206,267438,2647,1318,204070,3477,461653,1386,2413
			,330077,1197,2637,268877,3365,531109,2900,2922,398042,2395
			,1179,267415,2635,661067,1701,1748,398772,2742,2391,330031
			,1175,1611,200010,3749,527717,1452,2742,332397,2350,3222
			,268949,3402,3493,133973,1386,464219,605,2349,334123,2709
			,2890,267946,2773,592565,1210,2651,395863,1323,2707,265877 };

	Date begintime, endtime;

	CalcBirthdayBase();
	~CalcBirthdayBase();
	Date GetLunarCalendarMonth(SYSTEMTIME stime);
	std::wstring calcYear(INT32 year);
	std::wstring calcMonth(INT32 year, INT32 month);
	std::wstring calcDay(INT32 gzr);
	//判断是否为闰年
	bool IsLeap(INT32 year);
	//计算时间1-时间2的天数
	INT32 diffDate(Date begintime, SYSTEMTIME endtime);

	void _SetClipboardData(CString buffer);
};

