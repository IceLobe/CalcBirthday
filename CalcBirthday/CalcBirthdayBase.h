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
	std::wstring tgs = L"���ұ����켺�����ɹ�";
	std::wstring dzs = L"�ӳ���î������δ�����纥";

	std::wstring months[12] = { L"����", L"����", L"����", L"����", L"����", L"����", L"����", L"����", L"����", L"ʮ��", L"����", L"����" };
	std::wstring days[30] = { L"��һ", L"����", L"����", L"����", L"����", L"����", L"����", L"����", L"����", L"��ʮ", L"ʮһ", L"ʮ��", L"ʮ��", L"ʮ��", L"ʮ��", L"ʮ��", L"ʮ��", L"ʮ��", L"ʮ��", L"��ʮ", L"إһ", L"إ��", L"إ��", L"إ��", L"إ��", L"إ��", L"إ��", L"إ��", L"إ��", L"��ʮ" };

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
	//�ж��Ƿ�Ϊ����
	bool IsLeap(INT32 year);
	//����ʱ��1-ʱ��2������
	INT32 diffDate(Date begintime, SYSTEMTIME endtime);

	void _SetClipboardData(CString buffer);
};

