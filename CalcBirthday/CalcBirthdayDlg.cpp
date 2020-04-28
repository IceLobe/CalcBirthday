
// CalcBirthdayDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CalcBirthday.h"
#include "CalcBirthdayDlg.h"
#include "afxdialogex.h"
#include "CalcBirthdayBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcBirthdayDlg 对话框


CCalcBirthdayDlg::CCalcBirthdayDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCBIRTHDAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcBirthdayDlg::calcBirthday()
{
	SYSTEMTIME stime;
	monthCalendar.GetCurSel(&stime);

	CalcBirthdayBase cbb = CalcBirthdayBase();
	
	int days = cbb.diffDate(cbb.begintime, stime);

	UINT32 gzr = days % 60;

	std::wstring year = cbb.calcYear(stime.wYear);
	std::wstring month = cbb.calcMonth(stime.wYear, stime.wMonth);
	std::wstring day = cbb.calcDay(gzr);
	CString tmp(year.c_str());
	tmp.Append(month.c_str());
	tmp.Append(day.c_str());
	SetDlgItemText(IDC_TXTVALUE, tmp);
	CString rizhu(L"");
	rizhu.Format(L"%d", gzr);
	rizhu.Insert(0, L"日柱数为：");
	SetDlgItemText(IDC_TXTRIZHU, rizhu);
}

void CCalcBirthdayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MONTHCALEN, monthCalendar);
}

BEGIN_MESSAGE_MAP(CCalcBirthdayDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(MCN_SELECT, IDC_MONTHCALEN, &CCalcBirthdayDlg::OnMcnSelectMonthcalen)
END_MESSAGE_MAP()


// CCalcBirthdayDlg 消息处理程序

BOOL CCalcBirthdayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	calcBirthday();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalcBirthdayDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalcBirthdayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcBirthdayDlg::OnMcnSelectMonthcalen(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	calcBirthday();
	*pResult = 0;
}
