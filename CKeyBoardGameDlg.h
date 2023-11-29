#pragma once
#include "afxdialogex.h"


// CKeyBoardGameDlg 대화 상자

class CKeyBoardGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKeyBoardGameDlg)

public:
	CKeyBoardGameDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CKeyBoardGameDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CKeyBoardGameDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
