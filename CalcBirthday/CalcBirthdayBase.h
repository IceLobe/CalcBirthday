#pragma once

class CalcBirthdayBase
{
public:
	std::wstring tgs = L"���ұ����켺�����ɹ�";
	std::wstring dzs = L"�ӳ���î������δ�����纥";

	int gzr = 0;

	CalcBirthdayBase();
	~CalcBirthdayBase();

	std::wstring calcYear(int year);
	std::wstring calcMonth(int year,int month);
	std::wstring calcDay(CTime ctime);
};

