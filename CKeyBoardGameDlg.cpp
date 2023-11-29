// CKeyBoardGameDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Alarm.h"
#include "afxdialogex.h"
#include "CKeyBoardGameDlg.h"


// CKeyBoardGameDlg 대화 상자

IMPLEMENT_DYNAMIC(CKeyBoardGameDlg, CDialogEx)

CKeyBoardGameDlg::CKeyBoardGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CKeyBoardGameDlg, pParent)
{

}

CKeyBoardGameDlg::~CKeyBoardGameDlg()
{
}

void CKeyBoardGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoardGameDlg, CDialogEx)
END_MESSAGE_MAP()


// CKeyBoardGameDlg 메시지 처리기
