#pragma once
#include "afxdialogex.h"


// CWeatherAndTrafficDlg 대화 상자

class CWeatherAndTrafficDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWeatherAndTrafficDlg)

public:
	CWeatherAndTrafficDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CWeatherAndTrafficDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = WetherAndTrafficDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CFont m_font;
	afx_msg void OnStnClickedWeather();
	afx_msg void OnStnClickedTraffic();
};
