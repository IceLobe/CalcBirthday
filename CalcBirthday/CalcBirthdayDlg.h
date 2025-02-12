﻿
// CalcBirthdayDlg.h: 头文件
//

#pragma once


// CCalcBirthdayDlg 对话框
class CCalcBirthdayDlg : public CDialogEx
{
// 构造
public:
	CCalcBirthdayDlg(CWnd* pParent = nullptr);	// 标准构造函数

	void calcBirthday();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCBIRTHDAY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMcnSelectMonthcalen(NMHDR* pNMHDR, LRESULT* pResult);
	// 日期控件
	CMonthCalCtrl monthCalendar;
	afx_msg void OnMcnSelchangeMonthcalen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnSetfocusTxtlunarcalendar();
	afx_msg void OnEnSetfocusTxtvalue();
	afx_msg void OnEnSetfocusTxtrizhu();
};
