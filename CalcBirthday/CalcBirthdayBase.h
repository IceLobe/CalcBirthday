#pragma once

class CalcBirthdayBase
{
public:
	std::wstring tgs = L"¼×ÒÒ±û¶¡Îì¼º¸ıĞÁÈÉ¹ï";
	std::wstring dzs = L"×Ó³óÒúÃ®³½ËÈÎçÎ´ÉêÓÏĞçº¥";

	int gzr = 0;

	CalcBirthdayBase();
	~CalcBirthdayBase();

	std::wstring calcYear(int year);
	std::wstring calcMonth(int year,int month);
	std::wstring calcDay(CTime ctime);
};

