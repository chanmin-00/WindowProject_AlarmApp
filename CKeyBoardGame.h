#pragma once
#include "afxdialogex.h"


// CKeyBoardGame 대화 상자

class CKeyBoardGame : public CDialogEx
{
	DECLARE_DYNAMIC(CKeyBoardGame)

public:
	CKeyBoardGame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CKeyBoardGame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CKeyBoardGameDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:

	CString keyboardResult;
	CString TestProblem;
	afx_msg void OnBnClickedstart();
	afx_msg void OnEnChangekeyboardlimitsec();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedComplete1();
	CString keyboard_time_limit; // 에디트 컨트롤과 연결 변수
	CTime currentTime; // 현재시간
	CTime afterTime; // 경과시간
	int time_limit; // 시간 제한 설정을 위한 변수
	CFont m_font;
};
