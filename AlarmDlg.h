
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
	afx_msg bool KeyboardGame();
	int alarm_hour1; // 알람 설정 1의 시간 설정 변수
	int alarm_minute1; // 알람 설정 1의 분 설정 변수
	int alarm_type; // 몇 번째 알람에 대한 것인지 나타내는 flag 변수
	int alarm_hour2; // 알람 설정 2의 시간 설정 변수
	int alarm_minute2; // 알람 설정 2의 분 설정 변수
	int alarm_timer_id; // 알람 타이머 ID
	int alarm_timer_id1; // 1번 알람에 대한 타이머 id를 저장할 변수
	int alarm_timer_id2; // 2번 알람에 대한 타이머 id를 저장할 변수
	afx_msg void OnBnClickedMakeAlarm2();
	afx_msg void OnCbnSelchangeAmpm1();
	CString alarm_ampm1; // 알람 설정 1의 오전/오후 설정 변수
	CString alarm_ampm2; // 알람 설정 2의 오전/오후 설정 변수
	afx_msg void OnBnClickedAlarmDelete1();
	afx_msg void OnBnClickedAlarmDelete2();
};
