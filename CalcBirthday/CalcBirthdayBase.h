#pragma once
struct Date {
	UINT32 year;
	UINT32 month;
	UINT32 day;
};

class CalcBirthdayBase
{
	
public:
	std::wstring tgs = L"���ұ����켺�����ɹ�";
	std::wstring dzs = L"�ӳ���î������δ�����纥";

	Date begintime, endtime;

	CalcBirthdayBase();
	~CalcBirthdayBase();

	std::wstring calcYear(UINT32 year);
	std::wstring calcMonth(UINT32 year, UINT32 month);
	std::wstring calcDay(UINT32 gzr);
	//�ж��Ƿ�Ϊ����
	bool IsLeap(UINT32 year);
	//����ʱ��1-ʱ��2������
	UINT32 diffDate(Date begintime, SYSTEMTIME endtime);
};

