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

	DECLARE_MESSAGE_MAP()
public:

	CString keyboardResult;
	CString TestProblem;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedstart();
	afx_msg void OnEnChangekeyboardlimitsec();
	CString keyboard_time_limit;
	CTime currentTime; // 현재시간
	CTime afterTime; // 경과시간
	afx_msg void OnBnClickedOk();
	int time_limit;
	afx_msg void OnBnClickedComplete1();
};
