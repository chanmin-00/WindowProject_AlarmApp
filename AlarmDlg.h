
// AlarmDlg.h: 헤더 파일
//

#pragma once


// CAlarmDlg 대화 상자
class CAlarmDlg : public CDialogEx
{
// 생성입니다.
public:
	CAlarmDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALARM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeAmpm();
	afx_msg void OnEnChangeAmpm2();
	afx_msg void OnStnClickedMinutestr2();
	afx_msg void OnClickedMakeAlarm1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int alarm_hour1;
	int alarm_minute1;
	int alarm_type;
	int alarm_hour2;
	int alarm_minute2;
	afx_msg void OnBnClickedMakeAlarm2();
	afx_msg void OnCbnSelchangeAmpm1();
	CString alarm_ampm1;
	CString alarm_ampm2;
};
