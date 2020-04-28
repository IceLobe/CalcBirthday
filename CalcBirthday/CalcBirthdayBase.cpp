#include "pch.h"
#include "CalcBirthdayBase.h"




CalcBirthdayBase::CalcBirthdayBase()
{
	tgs = L"¼×ÒÒ±û¶¡Îì¼º¸ıĞÁÈÉ¹ï";
	dzs = L"×Ó³óÒúÃ®³½ËÈÎçÎ´ÉêÓÏĞçº¥";
}

CalcBirthdayBase::~CalcBirthdayBase()
{
}

std::wstring CalcBirthdayBase::calcYear(int year)
{
	int tg = (year - 4) % 10;
	int dz = (year - 4) % 12;
	return  tgs.substr(tg, 1) + dzs.substr(dz, 1);
}

std::wstring CalcBirthdayBase::calcMonth(int year, int month)
{
    std::wstring tg = L"", dz = L"";
    int num = (year - 4) % 5;
    switch (num)
    {
    case 0:
        tg = tgs.substr((month + 1) % 10);
        break;
    case 1:
        tg = tgs.substr((month + 3) % 10);
        break;
    case 2:
        tg = tgs.substr((month + 5) % 10);
        break;
    case 3:
        tg = tgs.substr((month + 7) % 10);
        break;
    case 4:
        tg = tgs.substr((month - 1) % 10);
        break;
    default:
        break;
    }
    dz = dzs.substr((month + 1) % 12);
    return tg + dz + L"ÔÂ";
}

std::wstring CalcBirthdayBase::calcDay(int year, int month, int day)
{
	return L"";
}
